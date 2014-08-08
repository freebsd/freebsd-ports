--- fcgi_protocol.c.orig
+++ fcgi_protocol.c
@@ -475,7 +475,7 @@
                         ap_log_rerror(FCGI_LOG_ERR_NOERRNO, fr->r,
                             "FastCGI: comm with server \"%s\" aborted: protocol error: "
                             "invalid FCGI_END_REQUEST size: "
-                            "%d != sizeof(FCGI_EndRequestBody)(%d)",
+                            "%d != sizeof(FCGI_EndRequestBody)(%zu)",
                             fr->fs_path, fr->dataLen, sizeof(FCGI_EndRequestBody));
                         return HTTP_INTERNAL_SERVER_ERROR;
                     }
