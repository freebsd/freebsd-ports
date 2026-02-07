--- mod_fastcgi.c.orig	2017-03-29 21:11:44 UTC
+++ mod_fastcgi.c
@@ -2219,7 +2219,7 @@ SERVER_SEND:
         if (select_status < 0)
         {
             ap_log_rerror(FCGI_LOG_ERR_ERRNO, r, "FastCGI: comm with server "
-                "\"%s\" aborted: select() failed", fr->fs_path);
+                "\"%s\" aborted: select() failed: \"%s\"", fr->fs_path, strerror(errno));
             state = STATE_ERROR;
             break;
         }
@@ -2302,7 +2302,7 @@ SERVER_SEND:
             	else 
             	{
                 ap_log_rerror(FCGI_LOG_ERR, r, "FastCGI: comm with server "
-                    "\"%s\" aborted: read failed", fr->fs_path);
+                    "\"%s\" aborted: read failed: \"%s\"", fr->fs_path, strerror(errno));
                 state = STATE_ERROR;
                 break;
             }
