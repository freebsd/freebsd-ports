--- src/T1_FontManager.cc.orig	Mon Jul 14 08:30:07 2003
+++ src/T1_FontManager.cc	Mon Jul 14 08:30:33 2003
@@ -77,7 +77,7 @@
 int
 T1_FontManager::SearchT1FontId(const char* fileName) const
 {
-  int n = T1_Get_no_fonts();
+  int n = T1_GetNoFonts();
   int i;
   for (i = 0; i < n && strcmp(fileName, T1_GetFontFileName(i)); i++) ;
 
