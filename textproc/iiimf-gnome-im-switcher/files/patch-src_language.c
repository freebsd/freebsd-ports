--- src/language.c.orig	Thu Apr 29 20:23:29 2004
+++ src/language.c	Wed Oct 13 22:52:28 2004
@@ -946,8 +946,8 @@
 gimlet_language_get_conversion_mode (char *iiim_lang_name)
 {
   GSList *tmp;
-  tmp = active_languages;
   GimletLanguage *lang;
+  tmp = active_languages;
 
   while (tmp != NULL)
     {
