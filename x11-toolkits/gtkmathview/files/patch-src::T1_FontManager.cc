--- src/T1_FontManager.cc.orig	Thu Jul 17 18:18:13 2003
+++ src/T1_FontManager.cc	Thu Oct 16 15:09:23 2003
@@ -77,8 +77,8 @@
 int
 T1_FontManager::SearchT1FontId(const char* fileName) const
 {
-  //int n = T1_GetNoFonts(); // version 5.0 of t1lib
-  int n = T1_Get_no_fonts();
+  int n = T1_GetNoFonts(); // version 5.0 of t1lib
+  //int n = T1_Get_no_fonts();
   int i;
   for (i = 0; i < n && strcmp(fileName, T1_GetFontFileName(i)); i++) ;
 
