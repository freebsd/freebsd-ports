--- agent/mibgroup/ucd-snmp/diskio.c.orig	Thu Mar  6 07:55:01 2003
+++ agent/mibgroup/ucd-snmp/diskio.c	Sat Mar 29 22:41:29 2003
@@ -49,7 +49,12 @@
 #endif                          /* bsdi */
 
 #if defined (freebsd4) || defined(freebsd5)
+#include <sys/param.h>
+#if __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
 #include <sys/dkstat.h>
+#endif
 #include <devstat.h>
 #endif                          /* freebsd */
 
@@ -380,7 +385,11 @@
     }
     memset(stat->dinfo, 0, sizeof(struct devinfo));
 
+#if defined(freebsd5) && (__FreeBSD_version >= 500107)
+    if ((devstat_getdevs(NULL, stat)) == -1) {
+#else
     if ((getdevs(stat)) == -1) {
+#endif
         fprintf(stderr, "Can't get devices:%s\n", devstat_errbuf);
         return 1;
     }
@@ -429,6 +438,20 @@
     case DISKIO_DEVICE:
         *var_len = strlen(stat->dinfo->devices[indx].device_name);
         return (u_char *) stat->dinfo->devices[indx].device_name;
+#if defined(freebsd5) && (__FreeBSD_version >= 500107)
+    case DISKIO_NREAD:
+        long_ret = (signed long) stat->dinfo->devices[indx].bytes[DEVSTAT_READ];
+        return (u_char *) & long_ret;
+    case DISKIO_NWRITTEN:
+        long_ret = (signed long) stat->dinfo->devices[indx].bytes[DEVSTAT_WRITE];
+        return (u_char *) & long_ret;
+    case DISKIO_READS:
+        long_ret = (signed long) stat->dinfo->devices[indx].operations[DEVSTAT_READ];
+        return (u_char *) & long_ret;
+    case DISKIO_WRITES:
+        long_ret = (signed long) stat->dinfo->devices[indx].operations[DEVSTAT_WRITE];
+        return (u_char *) & long_ret;
+#else
     case DISKIO_NREAD:
         long_ret = (signed long) stat->dinfo->devices[indx].bytes_read;
         return (u_char *) & long_ret;
@@ -441,6 +464,7 @@
     case DISKIO_WRITES:
         long_ret = (signed long) stat->dinfo->devices[indx].num_writes;
         return (u_char *) & long_ret;
+#endif
 
     default:
         ERROR_MSG("diskio.c: don't know how to handle this request.");
