https://github.com/scimmia9286/aribb24/commit/fa54dee41aa38560f02868b24f911a24c33780a8
--- src/aribb24_private.h.orig	2019-09-16 15:57:19 UTC
+++ src/aribb24_private.h
@@ -35,9 +35,9 @@ struct arib_instance_private_t
     char *psz_last_error;
 
     drcs_conversion_t *p_drcs_conv;
-    int i_drcs_num;
-    unsigned int drcs_conv_table[188];
-    char drcs_hash_table[188][32 + 1];
+    int i_drcs_num[15];
+    unsigned int drcs_conv_table[15][188];
+    char drcs_hash_table[15][188][32 + 1];
 };
 
 void arib_log( arib_instance_t *, const char *, ... );
