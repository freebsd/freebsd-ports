--- mod_fastcgi.c.orig	2011-12-12 15:37:24.211384000 +0800
+++ mod_fastcgi.c	2011-12-12 15:37:50.565004000 +0800
@@ -754,6 +754,11 @@
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
