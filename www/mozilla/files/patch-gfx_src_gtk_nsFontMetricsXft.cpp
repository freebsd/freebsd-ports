--- gfx/src/gtk/nsFontMetricsXft.cpp.orig	Tue Jan  6 19:20:28 2004
+++ gfx/src/gtk/nsFontMetricsXft.cpp	Fri Jan 16 22:36:20 2004
@@ -105,6 +105,7 @@
     FcPattern *mPattern;
     FcPattern *mFontName;
     FcCharSet *mCharset;
+    int        mNotXft;
 };
 
 class nsFontXftInfo;
@@ -1066,7 +1067,7 @@
     }
 
     nsFontXft *font = (nsFontXft *)mLoadedFonts.ElementAt(0);
-    if (font->HasChar(aChar))
+    if (font->HasChar(aChar) && font->GetXftFont())
         return font;
 
     // We failed to find the character in the best-match font, so load
@@ -1947,6 +1948,7 @@
     FcPatternReference(mFontName);
 
     mXftFont = nsnull;
+    mNotXft  = 0;
 
     // set up our charset
     mCharset = nsnull;
@@ -1973,7 +1975,7 @@
 XftFont *
 nsFontXft::GetXftFont(void)
 {
-    if (!mXftFont) {
+    if (!mXftFont && !mNotXft) {
         FcPattern *pat = FcFontRenderPrepare(0, mPattern, mFontName);
         if (!pat)
             return nsnull;
@@ -1992,8 +1994,10 @@
             FcPatternDel(pat, FC_SPACING);
 
         mXftFont = XftFontOpenPattern(GDK_DISPLAY(), pat);
-        if (!mXftFont)
+        if (!mXftFont) {
             FcPatternDestroy(pat);
+            mNotXft = 1;
+        }
     }
 
     return mXftFont;
