
$FreeBSD$

--- src/psh.h.orig
+++ src/psh.h
@@ -52,7 +52,6 @@
    the screen - BEL is a good example (only one yet:) */
 #define IGNORECHARS "\007"
 
-extern WINDOW* ShellWin, *HelpWin;
 extern PANEL*  ShellPanel, *HelpPanel;
 
 /* function declarations */
