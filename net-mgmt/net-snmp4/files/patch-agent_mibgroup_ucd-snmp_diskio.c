--- agent/mibgroup/ucd-snmp/diskio.c.orig	Fri Mar 28 12:58:32 2003
+++ agent/mibgroup/ucd-snmp/diskio.c	Fri Mar 28 13:21:04 2003
@@ -47,7 +47,11 @@
 #endif /* bsdi */
 
 #if defined (freebsd4) || defined(freebsd5)
+#include <sys/param.h>
+#if __FreeBSD_version < 500101
 #include <sys/dkstat.h>
+#endif
+#include <sys/resource.h>
 #include <devstat.h>
 #endif /* freebsd */
 
@@ -318,7 +322,11 @@
   }
   memset(stat->dinfo, 0, sizeof(struct devinfo));
 
+#if __FreeBSD_version > 500106
+  if ((devstat_getdevs(NULL, stat)) == -1){
+#else
   if ((getdevs(stat)) == -1){
+#endif
 	fprintf (stderr,"Can't get devices:%s\n", devstat_errbuf);
   	return 1;
   }
@@ -370,16 +378,32 @@
       *var_len = strlen(stat->dinfo->devices[indx].device_name);
       return (u_char *) stat->dinfo->devices[indx].device_name;
     case DISKIO_NREAD:
+#if __FreeBSD_version > 500106
+      long_ret = (signed long) stat->dinfo->devices[indx].bytes[DSM_TOTAL_BYTES_READ];
+#else
       long_ret = (signed long) stat->dinfo->devices[indx].bytes_read;
+#endif
       return (u_char *) & long_ret;
     case DISKIO_NWRITTEN:
+#if __FreeBSD_version > 500106
+      long_ret = (signed long) stat->dinfo->devices[indx].bytes[DSM_TOTAL_BYTES_WRITE];
+#else
       long_ret = (signed long) stat->dinfo->devices[indx].bytes_written;
+#endif
       return (u_char *) & long_ret;
     case DISKIO_READS:
+#if __FreeBSD_version > 500106
+      long_ret = (signed long) stat->dinfo->devices[indx].operations[DSM_TOTAL_TRANSFERS_READ];
+#else
       long_ret = (signed long) stat->dinfo->devices[indx].num_reads;
+#endif
       return (u_char *) & long_ret;
     case DISKIO_WRITES:
+#if __FreeBSD_version > 500106
+      long_ret = (signed long) stat->dinfo->devices[indx].operations[DSM_TOTAL_TRANSFERS_WRITE];
+#else
       long_ret = (signed long) stat->dinfo->devices[indx].num_writes;
+#endif
       return (u_char *) & long_ret;
 
     default:
