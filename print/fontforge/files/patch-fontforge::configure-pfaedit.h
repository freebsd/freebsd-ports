--- fontforge/configure-pfaedit.h.orig	Tue Oct 16 13:02:54 2007
+++ fontforge/configure-pfaedit.h	Tue Oct 16 13:03:25 2007
@@ -90,7 +90,7 @@
 /* Sometimes I want to create a glyph which is a word, and this command       */
 /*  makes that easy                                                           */
 /*									      */
-/* #define FONTFORGE_CONFIG_PASTEAFTER					      */
+#define FONTFORGE_CONFIG_PASTEAFTER
 /*									      */
 /* The paste after command pastes the contents of the clipboard into the      */
 /*  current glyph, translates that by the advance width of the current glyph  */
@@ -108,7 +108,7 @@
 /*  don't include code for it by default, but if you do want it simply define */
 /*  the following macro							      */
 /*									      */
-/* #define FONTFORGE_CONFIG_TILEPATH					      */
+#define FONTFORGE_CONFIG_TILEPATH
 /*									      */
 /* The tile path command uses the contents of the clipboard as a tile which is*/
 /*  applied to any selected paths, replacing them. It could be used to make a */
