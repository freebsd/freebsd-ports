--- src/http_display/httpd.c.orig	2025-05-01 10:34:03 UTC
+++ src/http_display/httpd.c
@@ -176,27 +176,14 @@ static void * http_server_dispatch(void *arg)
        { NULL, NULL, ".webp", "image/webp" }
     };
 
-   const struct lws_http_mount mount = {
-        (struct lws_http_mount *)NULL,	/* linked-list pointer to next*/
-        "/",		                    /* mountpoint in URL namespace on this vhost */
-        server_root,                    /* where to go on the filesystem for that */
-        "index.html",	                /* default filename if none given */
-        NULL,
-        NULL,
-        mime_types,
-        NULL,
-        0,
-        0,
-        0,
-        0,
-        0,
-        0,
-        LWSMPRO_FILE,	                /* mount type is a directory in a filesystem */
-        1,		                        /* strlen("/"), ie length of the mountpoint */
-        NULL,
-#if LWS_LIBRARY_VERSION_MAJOR <= 4 && LWS_LIBRARY_VERSION_MINOR < 3
-        { NULL, NULL } // sentinel
-#endif
+    const struct lws_http_mount mount = {
+	    .mount_next = NULL,
+	    .mountpoint = "/",
+	    .origin = server_root,
+	    .def = "index.html",
+	    .extra_mimetypes = mime_types,
+	    .origin_protocol = LWSMPRO_FILE,
+	    .mountpoint_len = 1,
     };
 
     memset(&info, 0, sizeof info);
