--- goldlib/hunspell/csutil.cxx.orig	Fri Feb 23 05:38:36 2007
+++ goldlib/hunspell/csutil.cxx	Fri Feb 23 05:40:11 2007
@@ -4942,7 +4942,7 @@
 */
 int get_utf_cs_len()
 {
-  return (int)get_utf_cs(false);
+  return (long)get_utf_cs(false);
 }
 
 static struct lang_map *get_lang2enc(bool what = true)
@@ -4980,7 +4980,7 @@
 
 const char * get_default_enc(const char * lang)
 {
-  int n = (int)get_lang2enc(false);
+  int n = (long)get_lang2enc(false);
   for (int i = 0; i < n; i++)
   {
     if (strcmp(lang, get_lang2enc()[i].lang) == 0)
@@ -4993,7 +4993,7 @@
 
 int get_lang_num(const char * lang)
 {
-  int n = (int)get_lang2enc(false);
+  int n = (long)get_lang2enc(false);
   for (int i = 0; i < n; i++)
   {
     if (strncmp(lang,get_lang2enc()[i].lang,2) == 0)
