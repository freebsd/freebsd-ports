--- kover/cddb_fill.cc.orig	Mon Dec 29 03:32:23 2003
+++ kover/cddb_fill.cc	Mon Dec 29 03:53:52 2003
@@ -67,6 +67,11 @@
 #include "proxy_auth.h"
 #include "categories.h"
 
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#define CDROM_LEADOUT 0xAA
+#endif
+
 extern "C" {
 
 #ifdef HAVE_LINUX_CDROM_H
@@ -263,6 +268,10 @@
         globals.cdrom_device = strdup("/dev/cdrom");
 
     if ((cd_fd = open(globals.cdrom_device, O_RDONLY | O_NONBLOCK)) < 0) {
+#ifdef __FreeBSD__
+        emit statusText(QString(tr("Error while opening "))
+                + QString(globals.cdrom_device));
+#else
         switch (errno) {
         case EACCES:
             emit statusText(QString(tr
@@ -281,9 +290,11 @@
             emit statusText(QString(tr("Unknown error while opening "))
                 + QString(globals.cdrom_device));
         }
+#endif
         return false;
     }
 
+#ifndef __FreeBSD__
     ds = ioctl(cd_fd, CDROM_DISC_STATUS);
 
     switch (ds) {
@@ -300,6 +311,7 @@
         return false;
     }
     _DEBUG_ fprintf(stderr, "CD opened: %d\n", ds);
+#endif
 
     return true;
 }
@@ -314,8 +326,13 @@
 
 bool CDDB_Fill::readTOC()
 {
+#ifdef __FreeBSD__
+    ioc_toc_header hdr;
+    ioc_read_toc_single_entry entry;
+#else
     cdrom_tochdr hdr;
     cdrom_tocentry entry;
+#endif
     int i, pos;
     _DEBUG_ fprintf(stderr, "Reading TOC\n");
 
@@ -327,7 +344,11 @@
 
     emit statusText(tr("Reading table of contents..."));
 
+#ifdef __FreeBSD__
+    if (ioctl(cd_fd, CDIOREADTOCHEADER, &hdr) == -1) {
+#else
     if (ioctl(cd_fd, CDROMREADTOCHDR, &hdr)) {
+#endif
         emit statusText(tr("Error while reading table of contents!"));
 
         return false;
@@ -336,24 +357,41 @@
     cdinfo.artist = "Artist";
     cdinfo.cdname = "Title";
     cdinfo.length = 0;
+#ifdef __FreeBSD__
+    cdinfo.ntracks = hdr.ending_track;
+#else
     cdinfo.ntracks = hdr.cdth_trk1;
-
+#endif
     cdinfo.trk.clear();
 
     for (i = 0; i <= cdinfo.ntracks; i++) {
         if (i == cdinfo.ntracks)
+#ifdef __FreeBSD__
+            entry.track = CDROM_LEADOUT;
+        else
+            entry.track = i + 1;
+        entry.address_format = CD_MSF_FORMAT;
+        if (ioctl(cd_fd, CDIOREADTOCENTRY, &entry) == -1) {
+#else
             entry.cdte_track = CDROM_LEADOUT;
         else
             entry.cdte_track = i + 1;
         entry.cdte_format = CDROM_MSF;
         if (ioctl(cd_fd, CDROMREADTOCENTRY, &entry)) {
+#endif
             emit statusText(tr("Error while reading TOC entry!"));
 
             return false;
         }
 
+#ifdef __FreeBSD__
+        cdinfo.trk.append(new track_info(i + 1, entry.entry.addr.msf.minute,
+                entry.entry.addr.msf.second, entry.entry.addr.msf.frame));
+
+#else
         cdinfo.trk.append(new track_info(i + 1, entry.cdte_addr.msf.minute,
                 entry.cdte_addr.msf.second, entry.cdte_addr.msf.frame));
+#endif
     }
 
     pos = cdinfo.trk.first()->length;
