--- gfx/src/gtk/nsFontMetricsXft.cpp.save	Thu Aug  7 12:14:49 2003
+++ gfx/src/gtk/nsFontMetricsXft.cpp	Thu Aug  7 12:33:45 2003
@@ -106,6 +106,7 @@
     FcPattern *mPattern;
     FcPattern *mFontName;
     FcCharSet *mCharset;
+    int        mNotXft;
 };
 
 class nsFontXftInfo;
@@ -1051,7 +1052,7 @@
     // font in our loaded list that supports the character
     for (PRInt32 i = 0, end = mLoadedFonts.Count(); i < end; ++i) {
         nsFontXft *font = (nsFontXft *)mLoadedFonts.ElementAt(i);
-        if (font->HasChar(PRUint32(aChar)))
+        if (font->HasChar(PRUint32(aChar)) && font->GetXftFont())
             return font;
     }
 
@@ -1492,7 +1493,7 @@
         // this character.
         for (PRInt32 j = 0, end = mLoadedFonts.Count(); j < end; ++j) {
             font = (nsFontXft *)mLoadedFonts.ElementAt(j);
-            if (font->HasChar(c)) {
+            if (font->HasChar(c) && font->GetXftFont()) {
                 currFont = font;
                 goto FoundFont; // for speed -- avoid "if" statement
             }
@@ -1922,6 +1923,7 @@
     FcPatternReference(mFontName);
 
     mXftFont = nsnull;
+    mNotXft  = 0;
 
     // set up our charset
     mCharset = nsnull;
@@ -1948,7 +1950,7 @@
 XftFont *
 nsFontXft::GetXftFont(void)
 {
-    if (!mXftFont) {
+    if (!mXftFont && !mNotXft) {
         FcPattern *pat = FcFontRenderPrepare(0, mPattern, mFontName);
         if (!pat)
             return nsnull;
@@ -1967,8 +1969,10 @@
             FcPatternDel(pat, FC_SPACING);
 
         mXftFont = XftFontOpenPattern(GDK_DISPLAY(), pat);
-        if (!mXftFont)
+        if (!mXftFont) {
             FcPatternDestroy(pat);
+            mNotXft = 1;
+        }
     }
 
     return mXftFont;
