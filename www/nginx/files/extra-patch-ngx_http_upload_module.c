--- ../nginx-upload-module-2.3.0/ngx_http_upload_module.c.orig
+++ ../nginx-upload-module-2.3.0/ngx_http_upload_module.c
@@ -1580,7 +1580,7 @@
                 /*
                  * If at least one filter succeeds, we pass the field
                  */
-                if(rc == 0)
+                if(rc >= 0)
                     pass_field = 1;
 #else
                 if(ngx_strncmp(f[i].text.data, u->field_name.data, u->field_name.len) == 0)
