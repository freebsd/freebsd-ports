--- gfx/src/gtk/nsFontMetricsXft.cpp.orig	Mon Mar 31 12:30:39 2003
+++ gfx/src/gtk/nsFontMetricsXft.cpp	Mon Mar 31 12:30:58 2003
@@ -84,6 +84,7 @@
     FcPattern *mPattern;
     FcPattern *mFontName;
     FcCharSet *mCharset;
+    int        mNotXft;
 };
 
 struct MozXftLangGroup {
@@ -375,7 +376,7 @@
         PRInt32 end = mLoadedFonts.Count();
         for (PRInt32 j = 0; j < end; ++j) {
             font = (nsFontXft *)mLoadedFonts.ElementAt(j);
-            if (FcCharSetHasChar(font->mCharset, c)) {
+            if (FcCharSetHasChar(font->mCharset, c) && font->GetXftFont()) {
                 currFont = font;
                 goto FoundFont; // for speed -- avoid "if" statement
             }
@@ -635,7 +636,7 @@
 
         for (PRInt32 j = 0, end = mLoadedFonts.Count(); j < end; ++j) {
             font = (nsFontXft *)mLoadedFonts.ElementAt(j);
-            if (FcCharSetHasChar(font->mCharset, c)) {
+            if (FcCharSetHasChar(font->mCharset, c) && font->GetXftFont()) {
                 currFont = font;
                 goto FoundFont; // for speed -- avoid "if" statement
             }
@@ -888,7 +889,7 @@
     // font in our loaded list that supports the character
     for (PRInt32 i = 0, end = mLoadedFonts.Count(); i < end; ++i) {
         nsFontXft *font = (nsFontXft *)mLoadedFonts.ElementAt(i);
-        if (FcCharSetHasChar(font->mCharset, aChar))
+        if (FcCharSetHasChar(font->mCharset, aChar) && font->GetXftFont() != NULL)
             return font;
     }
 
@@ -1051,7 +1052,7 @@
 
         for (PRInt32 j = 0, end = mLoadedFonts.Count(); j < end; ++j) {
             font = (nsFontXft *)mLoadedFonts.ElementAt(j);
-            if (FcCharSetHasChar(font->mCharset, c)) {
+            if (FcCharSetHasChar(font->mCharset, c) && font->GetXftFont()) {
                 currFont = font;
                 goto FoundFont; // for speed -- avoid "if" statement
             }
@@ -1461,6 +1462,7 @@
     FcPatternReference(mFontName);
 
     mXftFont = nsnull;
+    mNotXft  = 0;
 
     // set up our charset
     mCharset = nsnull;
@@ -1487,14 +1489,16 @@
 XftFont *
 nsFontXft::GetXftFont(void)
 {
-    if (!mXftFont) {
+    if (!mXftFont && !mNotXft) {
         FcPattern *pat = FcFontRenderPrepare(0, mPattern, mFontName);
         if (!pat)
             return nsnull;
 
         mXftFont = XftFontOpenPattern(GDK_DISPLAY(), pat);
-        if (!mXftFont)
+        if (!mXftFont) { 
             FcPatternDestroy(pat);
+	    mNotXft = 1;
+	}
     }
 
     return mXftFont;
