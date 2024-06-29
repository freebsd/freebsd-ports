--- tools/osinfo-db-validate.c.orig	2023-10-27 14:08:20 UTC
+++ tools/osinfo-db-validate.c
@@ -35,7 +35,12 @@ static void validate_structured_error_nop(void *userDa
 }
 
 static void validate_structured_error_nop(void *userData G_GNUC_UNUSED,
+#if LIBXML_VERSION >= 21200
+                                          const xmlError *error G_GNUC_UNUSED)
+#else
                                           xmlErrorPtr error G_GNUC_UNUSED)
+#endif
+					  
 {
     if (error->file)
         g_printerr("%s:%d %s", error->file, error->line, error->message);
