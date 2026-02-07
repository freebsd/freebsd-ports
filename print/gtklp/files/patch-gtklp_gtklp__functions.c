--- gtklp/gtklp_functions.c.orig	2019-11-01 16:27:28 UTC
+++ gtklp/gtklp_functions.c
@@ -57,17 +57,6 @@
 #include "conflict.xpm"
 #include "rarrow.xpm"
 
-unsigned topmargin, bottommargin, leftmargin, rightmargin;
-int imageScalingType;
-double imageScalingScalingValue;
-double imageScalingNaturalValue;
-double imageScalingPPIValue;
-int hasAskedPWD;
-
-ppd_file_t *printerPPD;
-
-GtkWidget *mainWindow;
-
 #if GTK_MAJOR_VERSION == 1
 GtkWidget *button_inst_save_label;
 #else
