--- mod_fastcgi.c.orig
+++ mod_fastcgi.c
@@ -753,6 +753,11 @@
             	continue;
             }
 
+            if (strcasecmp(name, "Content-Length") == 0) {
+                ap_set_content_length(r, strtol(value, NULL, 10));
+                continue;
+            }
+
             /* If the script wants them merged, it can do it */
             ap_table_add(r->err_headers_out, name, value);
             continue;
@@ -2215,7 +2220,7 @@
         if (select_status < 0)
         {
             ap_log_rerror(FCGI_LOG_ERR_ERRNO, r, "FastCGI: comm with server "
-                "\"%s\" aborted: select() failed", fr->fs_path);
+                "\"%s\" aborted: select() failed: \"%s\"", fr->fs_path, strerror(errno));
             state = STATE_ERROR;
             break;
         }
@@ -2298,7 +2303,7 @@
             	else 
             	{
             		ap_log_rerror(FCGI_LOG_ERR, r, "FastCGI: comm with server "
-            				"\"%s\" aborted: read failed", fr->fs_path);
+            				"\"%s\" aborted: read failed: \"%s\"", fr->fs_path, strerror(errno));
             		state = STATE_ERROR;
             		break;
             	}
