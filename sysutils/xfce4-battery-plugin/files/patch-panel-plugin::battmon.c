--- panel-plugin/battmon.c.orig	Fri Jul 18 15:15:29 2003
+++ panel-plugin/battmon.c	Fri Aug  1 12:14:50 2003
@@ -32,6 +32,10 @@
 
 #ifdef __FreeBSD__
 #include <machine/apm_bios.h>
+#include <fcntl.h>
+#ifndef APMDEVICE
+#define APMDEVICE "/dev/apm"
+#endif
 #elif __OpenBSD__
 #include <sys/param.h>
 #include <machine/apmvar.h>
@@ -187,6 +191,9 @@
 #else
 	struct apm_info apm;
 #endif
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
+	int fd;
+#endif
 	int charge;
 	int time_remaining;
 	gboolean acline;
@@ -217,8 +224,6 @@
      FreeBSD.  Each time this functions is called (once every second)
      the APM device is opened, read from and then closed.
   */
-  	int fd;
-
   	battmon->method = BM_BROKEN;
   	fd = open(APMDEVICE, O_RDONLY);
   	if (fd == -1) return TRUE;
@@ -232,12 +237,18 @@
   	time_remaining = apm.ai_batt_time;
 	time_remaining = time_remaining / 60; /* convert from seconds to minutes */
   	charge = apm.ai_batt_life;
+
+        /*
+         * Work around a bug in the FreeBSD ACPI APM emulation layer which will
+         * sometimes return funny values for the battery life.
+         */
+        if(charge > 100) {
+            charge = 100;
+        }
 #elif __OpenBSD__
   /* Code for OpenBSD by Joe Ammond <jra@twinight.org>. Using the same
      procedure as for FreeBSD.
   */
-  	int fd;
-
   	battmon->method = BM_BROKEN;
   	fd = open(APMDEVICE, O_RDONLY);
   	if (fd == -1) return TRUE;
