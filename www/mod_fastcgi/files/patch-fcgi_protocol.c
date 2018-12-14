--- fcgi_protocol.c.orig	2017-03-29 21:11:44 UTC
+++ fcgi_protocol.c
@@ -475,7 +475,7 @@ int fcgi_protocol_dequeue(pool *p, fcgi_request *fr)
                         ap_log_rerror(FCGI_LOG_ERR_NOERRNO, fr->r,
                             "FastCGI: comm with server \"%s\" aborted: protocol error: "
                             "invalid FCGI_END_REQUEST size: "
-                            "%d != sizeof(FCGI_EndRequestBody)(%ld)",
+                            "%d != sizeof(FCGI_EndRequestBody)(%zu)",
                             fr->fs_path, fr->dataLen, sizeof(FCGI_EndRequestBody));
                         return HTTP_INTERNAL_SERVER_ERROR;
                     }
