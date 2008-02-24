

Patch attached with submission follows:

--- panel-plugin/battery.c	(revision 3756)
+++ panel-plugin/battery.c	(working copy)
@@ -25,7 +25,7 @@
 #include <config.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && (defined(i386) || defined(__i386__))
 #include <machine/apm_bios.h>
 #elif __OpenBSD__
 #include <sys/param.h>
@@ -163,7 +163,9 @@
      except that is does not work on FreeBSD
 
   */
+#ifdef APMDEVICE
     struct apm_info apm;
+#endif
       int fd;
 
     /* First check to see if ACPI is available */
@@ -310,7 +312,9 @@
       acline = apm.ac_state ? TRUE : FALSE;
 
 #else
+#ifdef APMDEVICE
     struct apm_info apm;
+#endif
     DBG ("Updating battery status...");
 
     if(battmon->method == BM_BROKEN) {


