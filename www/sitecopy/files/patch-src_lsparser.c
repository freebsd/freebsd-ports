--- src/lsparser.c.orig	2005-10-24 13:09:55 UTC
+++ src/lsparser.c
@@ -182,6 +182,10 @@ static enum ls_result parse_file(ls_context_t *ctx, ch
         return fail(ctx, "Relative filename disallowed");
     }
 
+    /* drop garbage trailing permissions */
+    if (strlen(perms) > 10) {
+        perms[10] = '\0';
+    }
     if (perms[0] == '-') {
         /* Normal file */
         file->mode = parse_permissions(perms);
