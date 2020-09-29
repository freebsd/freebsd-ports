--- lib/sl_version.h.orig	2001-06-26 13:22:43 UTC
+++ lib/sl_version.h
@@ -39,9 +39,9 @@ void sl_info (void);
 
 void sl_warranty (void);
 
-int sl_major_version;
-int sl_minor_version;
-int sl_patch_level;
+extern int sl_major_version;
+extern int sl_minor_version;
+extern int sl_patch_level;
 
 __END_DECLS
 #endif /* _sl_version_h */
