--- gfx/src/gtk/nsFontMetricsXft.cpp.orig	Mon May 12 06:03:28 2003
+++ gfx/src/gtk/nsFontMetricsXft.cpp	Sat May 31 11:32:14 2003
@@ -90,6 +90,7 @@
     FcPattern *mPattern;
     FcPattern *mFontName;
     FcCharSet *mCharset;
+    int        mNotXft;
 };
 
 struct MozXftLangGroup {
@@ -772,7 +773,7 @@
     // font in our loaded list that supports the character
     for (PRInt32 i = 0, end = mLoadedFonts.Count(); i < end; ++i) {
         nsFontXft *font = (nsFontXft *)mLoadedFonts.ElementAt(i);
-        if (FcCharSetHasChar(font->mCharset, aChar))
+        if (FcCharSetHasChar(font->mCharset, aChar) && font->GetXftFont())
             return font;
     }
 
@@ -1194,7 +1195,7 @@
         for (PRInt32 j = 0, end = mLoadedFonts.Count(); j < end; ++j) {
             nsFontXft *font;
             font = (nsFontXft *)mLoadedFonts.ElementAt(j);
-            if (FcCharSetHasChar(font->mCharset, c)) {
+            if (FcCharSetHasChar(font->mCharset, c) && font->GetXftFont()) {
                 foundFont = font;
                 break;
             }
@@ -1503,6 +1504,7 @@
     FcPatternReference(mFontName);
 
     mXftFont = nsnull;
+    mNotXft  = 0;
 
     // set up our charset
     mCharset = nsnull;
@@ -1529,7 +1531,7 @@
 XftFont *
 nsFontXft::GetXftFont(void)
 {
-    if (!mXftFont) {
+    if (!mXftFont && !mNotXft) {
         FcPattern *pat = FcFontRenderPrepare(0, mPattern, mFontName);
         if (!pat)
             return nsnull;
@@ -1548,8 +1550,10 @@
             FcPatternDel(pat, FC_SPACING);
 
         mXftFont = XftFontOpenPattern(GDK_DISPLAY(), pat);
-        if (!mXftFont)
+        if (!mXftFont) {
             FcPatternDestroy(pat);
+            mNotXft = 1;
+        }
     }
 
     return mXftFont;
