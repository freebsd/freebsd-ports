--- ext/mpeg2enc/gstmpeg2encoptions.cc.orig	Mon Jul  5 19:54:18 2004
+++ ext/mpeg2enc/gstmpeg2encoptions.cc	Mon Jul  5 20:05:37 2004
@@ -267,11 +267,23 @@
  * Class init stuff.
  */
 
+#if !defined(_SC_NPROCESSORS_ONLN) && defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 GstMpeg2EncOptions::GstMpeg2EncOptions ():
 MPEG2EncOptions ()
 {
   /* autodetect number of CPUs */
+#if !defined(_SC_NPROCESSORS_ONLN) && defined(__FreeBSD__)
+  /* We need to use a sysctl to get the number of CPUs. */
+  size_t len = sizeof (num_cpus);
+
+  sysctlbyname ("hw.ncpu", &num_cpus, &len, NULL, 0);
+#else
   num_cpus = sysconf (_SC_NPROCESSORS_ONLN);
+#endif
   if (num_cpus < 0)
     num_cpus = 1;
   if (num_cpus > 32)
