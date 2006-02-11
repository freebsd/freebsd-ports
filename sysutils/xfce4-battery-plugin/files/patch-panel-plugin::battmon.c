--- panel-plugin/battmon.c.orig	Sat Feb 11 23:43:01 2006
+++ panel-plugin/battmon.c	Sat Feb 11 23:43:07 2006
@@ -33,6 +33,7 @@
 
 #ifdef __FreeBSD__
 #include <machine/apm_bios.h>
+#define APMDEVICE "/dev/apm"
 #elif __OpenBSD__
 #include <sys/param.h>
 #include <machine/apmvar.h>
@@ -362,6 +363,7 @@
 	
 	
 	if(charge < 0) charge = 0;
+        if(charge > 100) charge = 100;
 	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(battmon->battstatus), charge / 100.0);
 	
 	if(battmon->options.display_label){
