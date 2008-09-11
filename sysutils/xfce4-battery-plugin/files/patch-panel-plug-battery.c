--- panel-plugin/battery.c.orig	2008-09-04 17:53:40.000000000 -0300
+++ panel-plugin/battery.c	2008-09-10 21:53:56.000000000 -0300
@@ -26,7 +26,9 @@
 #endif
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__i386___)
 #include <machine/apm_bios.h>
+#endif
 #elif __OpenBSD__
 #include <sys/param.h>
 #include <machine/apmvar.h>
@@ -163,7 +165,9 @@
      except that is does not work on FreeBSD
 
   */
+#ifdef APMDEVICE
     struct apm_info apm;
+#endif
       int fd;
 
     /* First check to see if ACPI is available */
@@ -310,7 +314,9 @@
       acline = apm.ac_state ? TRUE : FALSE;
 
 #else
-    struct apm_info apm;
+#ifdef APMDEVICE    
+struct apm_info apm;
+#endif
     DBG ("Updating battery status...");
 
     if(battmon->method == BM_BROKEN) {
@@ -382,6 +388,7 @@
           rate = last_rate;
         }
 
+#ifdef __linux__
         charge = (((float)ccapacity)/((float)lcapacity))*100;
 
         if ( last_acline )
@@ -394,6 +401,17 @@
 
         last_acline = acline;
 
+#elif __FreeBSD__
+	charge = acpistate->percentage;
+	
+	if ( last_acline)
+	    time_remaining = acpistate->rtime;
+	else
+	    time_remaining = acpistate->rtime;
+
+	if ( time_remaining < 0 )
+	    time_remaining = 0;
+#endif
     }
 #ifdef __linux__
     else {
