--- fontforge/configure-pfaedit.h.orig	Sat Jan  8 11:11:45 2005
+++ fontforge/configure-pfaedit.h	Thu Jan 20 16:53:29 2005
@@ -73,7 +73,7 @@
 /* Sometimes I want to create a glyph which is a word, and this command       */
 /*  makes that easy                                                           */
 /*									      */
-/* #define FONTFORGE_CONFIG_PASTEAFTER					      */
+#define FONTFORGE_CONFIG_PASTEAFTER
 /*									      */
 /* The paste after command pastes the contents of the clipboard into the      */
 /*  current glyph, translates that by the advance width of the current glyph  */
@@ -84,7 +84,7 @@
 /*  don't include code for it by default, but if you do want it simply define */
 /*  the following macro							      */
 /*									      */
-/* #define FONTFORGE_CONFIG_TILEPATH					      */
+#define FONTFORGE_CONFIG_TILEPATH
 /*									      */
 /* The tile path command uses the contents of the clipboard as a tile which is*/
 /*  applied to any selected paths, replacing them. It could be used to make a */
@@ -190,7 +190,7 @@
 /*  routine. I'm not sure that it's very useful though. It can be used to do  */
 /*  perspective transformations and such				      */
 /*									      */
-/* #define FONTFORGE_CONFIG_NONLINEAR					      */
+#define FONTFORGE_CONFIG_NONLINEAR
 /*									      */
 /* This command takes two strings which specify general expressions in x and y*/
 /*  and applies the specified transformations to the splines.  Note: Each     */
