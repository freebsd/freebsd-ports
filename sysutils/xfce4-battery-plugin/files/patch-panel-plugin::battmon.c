--- panel-plugin/battmon.c.orig	Fri Sep 12 23:38:01 2003
+++ panel-plugin/battmon.c	Fri Sep 12 23:38:24 2003
@@ -362,6 +362,7 @@
 	
 	
 	if(charge < 0) charge = 0;
+        if(charge > 100) charge = 100;
 	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(battmon->battstatus), charge / 100.0);
 	
 	if(battmon->options.display_label){
