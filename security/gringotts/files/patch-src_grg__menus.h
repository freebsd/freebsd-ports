--- src/grg_menus.h.orig	2008-01-04 13:08:44 UTC
+++ src/grg_menus.h
@@ -25,19 +25,19 @@
 #include <gtk/gtk.h>
 
 /* menu File */
-GtkWidget *bnew, *bopen, *bsave, *bsas, *brev, *bclose, *bquit;
+extern GtkWidget *bnew, *bopen, *bsave, *bsas, *brev, *bclose, *bquit;
 
 /* menu Edit */
-GtkWidget *badd, *brem, *bcut, *bcop, *bpaste, *bfind, *bfinda, *bpwd, *bpref;
+extern GtkWidget *badd, *brem, *bcut, *bcop, *bpaste, *bfind, *bfinda, *bpwd, *bpref;
 
 /* menu Navigation */
-GtkWidget *bmfirst, *bmback, *bmfor, *bmlast, *bmind;
+extern GtkWidget *bmfirst, *bmback, *bmfor, *bmlast, *bmind;
 
 /* menu Tools */
-GtkWidget *bwipe;
+extern GtkWidget *bwipe;
 
 /* menu Help */
-GtkWidget *babo;
+extern GtkWidget *babo;
 
 /*Makes a menubar, within a handlebox, and returns the GtkWidget */
 GtkWidget *grg_menu_create (GtkWidget * window);
