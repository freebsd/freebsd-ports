--- ulxmlrpcpp/ulxr_http_protocol.cpp.orig	Sat Mar  4 03:40:46 2006
+++ ulxmlrpcpp/ulxr_http_protocol.cpp	Mon Apr 17 02:00:48 2006
@@ -153,7 +153,7 @@
     pimpl->userTempFields.clear();
     pimpl->bAcceptcookies = false;
     pimpl->bChunkedEncoding = false;
-    pimpl->chunk_data.clear();
+    pimpl->chunk_data.erase();
     pimpl->chunk_size = 0;
     pimpl->chunk_body_skip = 0;
     setChunkedTransfer(false);
@@ -168,7 +168,7 @@
     pimpl->headerprops.clear();
     pimpl->cookies.clear();
     pimpl->bChunkedEncoding = false;
-    pimpl->chunk_data.clear();
+    pimpl->chunk_data.erase();
     pimpl->chunk_size = 0;
     pimpl->chunk_body_skip = 0;
     pimpl->chunk_terminated = false;
@@ -444,7 +444,7 @@
           len--;
           if (--pimpl->chunk_body_skip <= 0)
           {
-            pimpl->chunk_data.clear();
+            pimpl->chunk_data.erase();
             setConnectionState(State(ConnChunkHeader));
           }
         break;
@@ -523,7 +523,7 @@
               ULXR_TRACE(ULXR_PCHAR("have chunked transfer encoding"));
               pimpl->bChunkedEncoding = true;
               pimpl->chunk_size = 0;
-              pimpl->chunk_data.clear();
+              pimpl->chunk_data.erase();
           }
       }
 
