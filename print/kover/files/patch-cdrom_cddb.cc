--- kover/cdrom_cddb.cc.orig	Mon Dec 29 04:01:52 2003
+++ kover/cdrom_cddb.cc	Mon Dec 29 04:08:20 2003
@@ -31,6 +31,11 @@
 #include "cdrom_cddb.h"
 #include <stdio.h>
 
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#define CDROM_LEADOUT 0xAA
+#endif
+
 cdrom_cddb::cdrom_cddb(char *path):cdrom(path)
 {
     open();
@@ -49,8 +54,13 @@
 
 void cdrom_cddb::calc_cddb_id()
 {
+#ifdef __FreeBSD__
+    ioc_toc_header hdr;
+    ioc_read_toc_single_entry entry;
+#else
     cdrom_tochdr hdr;
     cdrom_tocentry entry;
+#endif
     int i = 0;
     int pos = 0;
     int length = 0;
@@ -62,13 +72,28 @@
         exit(0);
     }
 
+#ifdef __FreeBSD__
+    if (ioctl(cdrom_fd, CDIOREADTOCHEADER, &hdr) == -1) {
+#else
     if (ioctl(cdrom_fd, CDROMREADTOCHDR, &hdr)) {
+#endif
         fprintf(stderr,
             "%s:error while reading table of contents. exiting now!\n",
             PACKAGE);
         exit(0);
     }
 
+#ifdef __FreeBSD__
+    i = ntracks = hdr.ending_track;
+
+    do {
+        if (i == ntracks)
+            entry.track = CDROM_LEADOUT;
+        else
+            entry.track = i + 1;
+        entry.address_format = CD_MSF_FORMAT;
+        if (ioctl(cdrom_fd, CDIOREADTOCENTRY, &entry)) {
+#else
     i = ntracks = hdr.cdth_trk1;
 
     do {
@@ -78,12 +103,25 @@
             entry.cdte_track = i + 1;
         entry.cdte_format = CDROM_MSF;
         if (ioctl(cdrom_fd, CDROMREADTOCENTRY, &entry)) {
+#endif
             fprintf(stderr,
                 "%s:error while reading toc entry. exiting now!\n", PACKAGE);
             exit(0);
         }
         if (i != ntracks)
             pos +=
+#ifdef __FreeBSD__
+                cddb_sum((entry.entry.addr.msf.minute * 60) +
+                entry.entry.addr.msf.second);
+        if (i == 0)
+            length =
+                length - ((entry.entry.addr.msf.minute * 60) +
+                entry.entry.addr.msf.second);
+        if (i == ntracks)
+            length =
+                (entry.entry.addr.msf.minute * 60) +
+                entry.entry.addr.msf.second;
+#else
                 cddb_sum((entry.cdte_addr.msf.minute * 60) +
                 entry.cdte_addr.msf.second);
         if (i == 0)
@@ -94,6 +132,7 @@
             length =
                 (entry.cdte_addr.msf.minute * 60) +
                 entry.cdte_addr.msf.second;
+#endif
 
     } while (i--);
 
