--- plugins/reports/xmlmod/xmlmod.c.orig	Wed Dec 20 15:58:15 2006
+++ plugins/reports/xmlmod/xmlmod.c	Thu Dec 21 16:59:22 2006
@@ -58,7 +58,7 @@
         size_t ret;
         
         ret = fwrite(buf, 1, len, context);
-        if ( ret != (size_t ) len && ferror(context) ) {
+        if ( ret != (size_t ) len && ferror((FILE *) context) ) {
                 prelude_log(PRELUDE_LOG_ERR, "could not write IDMEF-XML data: '%s'.\n", strerror(errno));
                 return -1;
         }
