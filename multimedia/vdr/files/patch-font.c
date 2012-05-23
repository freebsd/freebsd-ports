--- font.c.orig
+++ font.c
@@ -486,7 +486,8 @@ cString cFont::GetFontFileName(const cha
      FcPatternAddBool(pat, FC_SCALABLE, FcTrue);
      FcConfigSubstitute(NULL, pat, FcMatchPattern);
      FcDefaultSubstitute(pat);
-     FcFontSet *fontset = FcFontSort(NULL, pat, FcFalse, NULL, NULL);
+     FcResult fresult;
+     FcFontSet *fontset = FcFontSort(NULL, pat, FcFalse, NULL, &fresult);
      if (fontset) {
         for (int i = 0; i < fontset->nfont; i++) {
             FcBool scalable;
