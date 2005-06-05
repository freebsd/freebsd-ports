--- uim/context.h.orig	Sat Feb  5 11:50:05 2005
+++ uim/context.h	Sun Jun  5 16:43:06 2005
@@ -156,13 +156,16 @@
 
 #ifdef ENABLE_NLS
 #define UIM_PREPARE_SAVING_TEXTDOMAIN_CODESET() \
-    const char *orig_encoding, *client_encoding;
+    char *enc, *orig_encoding = NULL; \
+    const char *client_encoding;
 #define UIM_SWITCH_TEXTDOMAIN_CODESET(uc) \
-  orig_encoding = bind_textdomain_codeset(GETTEXT_PACKAGE, NULL); \
+  if ((enc = bind_textdomain_codeset(GETTEXT_PACKAGE, NULL))) \
+    orig_encoding = strdup(enc); \
   client_encoding = (uc) ? ((struct uim_context_ *)uc)->encoding : uim_last_client_encoding; \
   bind_textdomain_codeset(GETTEXT_PACKAGE, client_encoding);
 #define UIM_RESTORE_TEXTDOMAIN_CODESET() \
-  bind_textdomain_codeset(GETTEXT_PACKAGE, orig_encoding);
+  bind_textdomain_codeset(GETTEXT_PACKAGE, orig_encoding); \
+  free(orig_encoding);
 #else  /* ENABLE_NLS */
 #define UIM_PREPARE_SAVING_TEXTDOMAIN_CODESET()
 #define UIM_SWITCH_TEXTDOMAIN_CODESET(uc)
