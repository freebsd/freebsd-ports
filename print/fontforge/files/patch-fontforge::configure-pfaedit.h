--- pfaedit/configure-pfaedit.h.orig	Tue May 13 03:20:08 2003
+++ pfaedit/configure-pfaedit.h	Tue May 13 10:24:58 2003
@@ -31,7 +31,7 @@
 /*  don't include code for it by default, but if you do want it simply define */
 /*  the following macro							      */
 /*									      */
-/* #define PFAEDIT_CONFIG_TILEPATH					      */
+#define PFAEDIT_CONFIG_TILEPATH
 /*									      */
 /* The tile path command uses the contents of the clipboard as a tile which is*/
 /*  applied to any selected paths, replacing them. It could be used to make a */
@@ -42,7 +42,7 @@
 /*  routine. I'm not sure that it's very useful though. It can be used to do  */
 /*  perspective transformations and such				      */
 /*									      */
-/* #define PFAEDIT_CONFIG_NONLINEAR					      */
+#define PFAEDIT_CONFIG_NONLINEAR
 /*									      */
 /* This command takes two strings which specify general expressions in x and y*/
 /*  and applies the specified transformations to the splines.  Note: Each     */
