--- libtransmission/rpc-server.c.orig
+++ libtransmission/rpc-server.c
@@ -33,4 +33,5 @@
 #include "list.h"
 #include "platform.h"
+#include "ptrarray.h"
 #include "rpcimpl.h"
 #include "rpc-server.h"
@@ -84,4 +85,34 @@
 
 
+/***
+****
+***/
+
+static char*
+get_current_session_id( struct tr_rpc_server * server )
+{
+    const time_t now = time( NULL );
+
+    if( !server->sessionId || ( now >= server->sessionIdExpiresAt ) )
+    {
+        int i;
+        const int n = 48;
+        const char * pool = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
+        const size_t pool_size = strlen( pool );
+        char * buf = tr_new( char, n+1 );
+
+        for( i=0; i<n; ++i )
+            buf[i] = pool[ tr_cryptoRandInt( pool_size ) ];
+        buf[n] = '\0';
+
+        tr_free( server->sessionId );
+        server->sessionId = buf;
+        server->sessionIdExpiresAt = now + (60*60); /* expire in an hour */
+    }
+
+    return server->sessionId;
+}
+
+
 /**
 ***
@@ -105,8 +136,6 @@
 
 static const char*
-tr_memmem( const char * s1,
-           size_t       l1,
-           const char * s2,
-           size_t       l2 )
+tr_memmem( const char * s1, size_t l1, /* haystack */
+           const char * s2, size_t l2 ) /* needle */
 {
     if( !l2 ) return s1;
@@ -122,4 +151,65 @@
 }
 
+struct tr_mimepart
+{
+    char * headers;
+    int headers_len;
+    char * body;
+    int body_len;
+};
+
+static void
+tr_mimepart_free( struct tr_mimepart * p )
+{
+    tr_free( p->body );
+    tr_free( p->headers );
+    tr_free( p );
+}
+
+static void
+extract_parts_from_multipart( const struct evkeyvalq * headers,
+                              const struct evbuffer * body,
+                              tr_ptrArray * setme_parts )
+{
+    const char * content_type = evhttp_find_header( headers, "Content-Type" );
+    const char * in = (const char*) EVBUFFER_DATA( body );
+    size_t inlen = EVBUFFER_LENGTH( body );
+
+    const char * boundary_key = "boundary=";
+    const char * boundary_key_begin = strstr( content_type, boundary_key );
+    const char * boundary_val = boundary_key_begin ? boundary_key_begin + strlen( boundary_key ) : "arglebargle";
+    char * boundary = tr_strdup_printf( "--%s", boundary_val );
+    const size_t boundary_len = strlen( boundary );
+
+    const char * delim = tr_memmem( in, inlen, boundary, boundary_len );
+    while( delim )
+    {
+        size_t part_len;
+        const char * part = delim + boundary_len;
+
+        inlen -= ( part - in );
+        in = part;
+
+        delim = tr_memmem( in, inlen, boundary, boundary_len );
+        part_len = delim ? (size_t)( delim - part ) : inlen;
+
+        if( part_len )
+        {
+            const char * rnrn = tr_memmem( part, part_len, "\r\n\r\n", 4 );
+            if( rnrn )
+            {
+                struct tr_mimepart * p = tr_new( struct tr_mimepart, 1 );
+                p->headers_len = rnrn - part;
+                p->headers = tr_strndup( part, p->headers_len );
+                p->body_len = (part+part_len) - (rnrn + 4);
+                p->body = tr_strndup( rnrn+4, p->body_len );
+                tr_ptrArrayAppend( setme_parts, p );
+            }
+        }
+    }
+
+    tr_free( boundary );
+}
+
 static void
 handle_upload( struct evhttp_request * req,
@@ -132,74 +222,65 @@
     else
     {
-        const char * content_type = evhttp_find_header( req->input_headers,
-                                                        "Content-Type" );
+        int i;
+        int n;
+        tr_bool hasSessionId = FALSE;
+        tr_ptrArray parts = TR_PTR_ARRAY_INIT;
 
         const char * query = strchr( req->uri, '?' );
-        const int    paused = query && strstr( query + 1, "paused=true" );
-
-        const char * in = (const char *) EVBUFFER_DATA( req->input_buffer );
-        size_t       inlen = EVBUFFER_LENGTH( req->input_buffer );
-
-        const char * boundary_key = "boundary=";
-        const char * boundary_key_begin = strstr( content_type,
-                                                  boundary_key );
-        const char * boundary_val =
-            boundary_key_begin ? boundary_key_begin +
-            strlen( boundary_key ) : "arglebargle";
-
-        char *       boundary = tr_strdup_printf( "--%s", boundary_val );
-        const size_t boundary_len = strlen( boundary );
-
-        const char * delim = tr_memmem( in, inlen, boundary, boundary_len );
-        while( delim )
-        {
-            size_t       part_len;
-            const char * part = delim + boundary_len;
-            inlen -= ( part - in );
-            in = part;
-            delim = tr_memmem( in, inlen, boundary, boundary_len );
-            part_len = delim ? (size_t)( delim - part ) : inlen;
-
-            if( part_len )
+        const tr_bool paused = query && strstr( query + 1, "paused=true" );
+
+        extract_parts_from_multipart( req->input_headers, req->input_buffer, &parts );
+        n = tr_ptrArraySize( &parts );
+
+        /* first look for the session id */
+        for( i=0; i<n; ++i ) {
+            struct tr_mimepart * p = tr_ptrArrayNth( &parts, i );
+            if( tr_memmem( p->headers, p->headers_len, TR_RPC_SESSION_ID_HEADER, strlen( TR_RPC_SESSION_ID_HEADER ) ) )
+                break;
+        }
+        if( i<n ) {
+            const struct tr_mimepart * p = tr_ptrArrayNth( &parts, i );
+            const char * ours = get_current_session_id( server );
+            const int ourlen = strlen( ours );
+            hasSessionId = ourlen<=p->body_len && !memcmp( p->body, ours, ourlen );
+        }
+
+        if( !hasSessionId )
+        {
+            send_simple_response( req, 409, NULL );
+        }
+        else for( i=0; i<n; ++i )
+        {
+            struct tr_mimepart * p = tr_ptrArrayNth( &parts, i );
+            if( strstr( p->headers, "filename=\"" ) )
             {
-                char * text = tr_strndup( part, part_len );
-                if( strstr( text, "filename=\"" ) )
-                {
-                    const char * body = strstr( text, "\r\n\r\n" );
-                    if( body )
-                    {
-                        char * b64;
-                        size_t  body_len;
-                        tr_benc top, *args;
-                        struct evbuffer * json = tr_getBuffer( );
-
-                        body += 4; /* walk past the \r\n\r\n */
-                        body_len = part_len - ( body - text );
-                        if( body_len >= 2
-                          && !memcmp( &body[body_len - 2], "\r\n", 2 ) )
-                            body_len -= 2;
-
-                        tr_bencInitDict( &top, 2 );
-                        args = tr_bencDictAddDict( &top, "arguments", 2 );
-                        tr_bencDictAddStr( &top, "method", "torrent-add" );
-                        b64 = tr_base64_encode( body, body_len, NULL );
-                        tr_bencDictAddStr( args, "metainfo", b64 );
-                        tr_bencDictAddBool( args, "paused", paused );
-                        tr_bencSaveAsJSON( &top, json );
-                        tr_rpc_request_exec_json( server->session,
-                                                  EVBUFFER_DATA( json ),
-                                                  EVBUFFER_LENGTH( json ),
-                                                  NULL, NULL );
-
-                        tr_releaseBuffer( json );
-                        tr_free( b64 );
-                        tr_bencFree( &top );
-                    }
-                }
-                tr_free( text );
+                char * b64;
+                int body_len = p->body_len;
+                tr_benc top, *args;
+                const char * body = p->body;
+                struct evbuffer * json = evbuffer_new( );
+
+                if( body_len >= 2 && !memcmp( &body[body_len - 2], "\r\n", 2 ) )
+                    body_len -= 2;
+
+                tr_bencInitDict( &top, 2 );
+                args = tr_bencDictAddDict( &top, "arguments", 2 );
+                tr_bencDictAddStr( &top, "method", "torrent-add" );
+                b64 = tr_base64_encode( body, body_len, NULL );
+                tr_bencDictAddStr( args, "metainfo", b64 );
+                tr_bencDictAddBool( args, "paused", paused );
+                tr_bencSaveAsJSON( &top, json );
+                tr_rpc_request_exec_json( server->session,
+                                          EVBUFFER_DATA( json ),
+                                          EVBUFFER_LENGTH( json ),
+                                          NULL, NULL );
+
+                evbuffer_free( json );
+                tr_free( b64 );
+                tr_bencFree( &top );
             }
         }
 
-        tr_free( boundary );
+        tr_ptrArrayDestruct( &parts, (PtrArrayForeachFunc)tr_mimepart_free );
 
         /* use xml here because json responses to file uploads is trouble.
@@ -474,30 +555,4 @@
 }
 
-static char*
-get_current_session_id( struct tr_rpc_server * server )
-{
-    const time_t now = time( NULL );
-
-    if( !server->sessionId || ( now >= server->sessionIdExpiresAt ) )
-    {
-        int i;
-        const int n = 48;
-        const char * pool = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
-        const size_t pool_size = strlen( pool );
-        char * buf = tr_new( char, n+1 );
-
-        for( i=0; i<n; ++i )
-            buf[i] = pool[ tr_cryptoRandInt( pool_size ) ];
-        buf[n] = '\0';
-
-        tr_free( server->sessionId );
-        server->sessionId = buf;
-        server->sessionIdExpiresAt = now + (60*60); /* expire in an hour */
-    }
-
-    return server->sessionId;
-}
-
-
 static tr_bool
 test_session_id( struct tr_rpc_server * server, struct evhttp_request * req )
@@ -567,4 +622,8 @@
         {
             handle_clutch( req, server );
+        }
+        else if( !strncmp( req->uri, "/transmission/upload", 20 ) )
+        {
+            handle_upload( req, server );
         }
 #ifdef REQUIRE_SESSION_ID
@@ -594,8 +653,4 @@
             handle_rpc( req, server );
         }
-        else if( !strncmp( req->uri, "/transmission/upload", 20 ) )
-        {
-            handle_upload( req, server );
-        }
         else
         {
