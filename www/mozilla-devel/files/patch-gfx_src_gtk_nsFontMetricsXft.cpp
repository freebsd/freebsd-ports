--- gfx/src/gtk/nsFontMetricsXft.cpp.orig	Tue Nov 25 21:44:50 2003
+++ gfx/src/gtk/nsFontMetricsXft.cpp	Sun Dec  7 15:20:48 2003
@@ -105,6 +105,7 @@
     FcPattern *mPattern;
     FcPattern *mFontName;
     FcCharSet *mCharset;
+    int        mNotXft;
 };
 
 class nsFontXftInfo;
@@ -1093,7 +1094,7 @@
 
     for (PRInt32 i = 1, end = mLoadedFonts.Count(); i < end; ++i) {
         nsFontXft *font = (nsFontXft *)mLoadedFonts.ElementAt(i);
-        if (font->HasChar(PRUint32(aChar)))
+        if (font->HasChar(PRUint32(aChar)) && font->GetXftFont())
             return font;
     }
 
@@ -1960,6 +1961,7 @@
     FcPatternReference(mFontName);
 
     mXftFont = nsnull;
+    mNotXft  = 0;
 
     // set up our charset
     mCharset = nsnull;
@@ -1986,7 +1988,7 @@
 XftFont *
 nsFontXft::GetXftFont(void)
 {
-    if (!mXftFont) {
+    if (!mXftFont && !mNotXft) {
         FcPattern *pat = FcFontRenderPrepare(0, mPattern, mFontName);
         if (!pat)
             return nsnull;
@@ -2005,8 +2007,10 @@
             FcPatternDel(pat, FC_SPACING);
 
         mXftFont = XftFontOpenPattern(GDK_DISPLAY(), pat);
-        if (!mXftFont)
+        if (!mXftFont) {
             FcPatternDestroy(pat);
+            mNotXft = 1;
+        }
     }
 
     return mXftFont;
