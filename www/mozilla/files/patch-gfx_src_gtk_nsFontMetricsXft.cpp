--- gfx/src/gtk/nsFontMetricsXft.cpp.orig	Thu May 29 19:10:54 2003
+++ gfx/src/gtk/nsFontMetricsXft.cpp	Mon Jun 30 23:11:39 2003
@@ -90,6 +90,7 @@
     FcPattern *mPattern;
     FcPattern *mFontName;
     FcCharSet *mCharset;
+    int        mNotXft;
 };
 
 struct MozXftLangGroup {
@@ -774,7 +775,7 @@
     // font in our loaded list that supports the character
     for (PRInt32 i = 0, end = mLoadedFonts.Count(); i < end; ++i) {
         nsFontXft *font = (nsFontXft *)mLoadedFonts.ElementAt(i);
-        if (FcCharSetHasChar(font->mCharset, aChar))
+        if (FcCharSetHasChar(font->mCharset, aChar) && font->GetXftFont())
             return font;
     }
 
@@ -1196,7 +1197,7 @@
         for (PRInt32 j = 0, end = mLoadedFonts.Count(); j < end; ++j) {
             nsFontXft *font;
             font = (nsFontXft *)mLoadedFonts.ElementAt(j);
-            if (FcCharSetHasChar(font->mCharset, c)) {
+            if (FcCharSetHasChar(font->mCharset, c) && font->GetXftFont()) {
                 foundFont = font;
                 break;
             }
@@ -1566,6 +1567,7 @@
     FcPatternReference(mFontName);
 
     mXftFont = nsnull;
+    mNotXft  = 0;
 
     // set up our charset
     mCharset = nsnull;
@@ -1592,7 +1594,7 @@
 XftFont *
 nsFontXft::GetXftFont(void)
 {
-    if (!mXftFont) {
+    if (!mXftFont && !mNotXft) {
         FcPattern *pat = FcFontRenderPrepare(0, mPattern, mFontName);
         if (!pat)
             return nsnull;
@@ -1611,8 +1613,10 @@
             FcPatternDel(pat, FC_SPACING);
 
         mXftFont = XftFontOpenPattern(GDK_DISPLAY(), pat);
-        if (!mXftFont)
+        if (!mXftFont) {
             FcPatternDestroy(pat);
+            mNotXft = 1;
+        }
     }
 
     return mXftFont;
