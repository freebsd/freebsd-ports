--- src/nwc_fsentry.cc.orig	2026-10-17 15:44:21 UTC
+++ src/nwc_fsentry.cc
@@ -83,11 +83,11 @@ namespace NWC
           _dest_statbuf.lastmod = stbuf.st_mtim;
           _dest_statbuf.lastchange = stbuf.st_ctim;
 #else
-          _dest_statbuf.lastaccess.tv_sec = stbuf.atime;
+          _dest_statbuf.lastaccess.tv_sec = stbuf.st_atime;
           _dest_statbuf.lastaccess.tv_nsec = 0;
-          _dest_statbuf.lastmod.tv_sec = stbuf.mtime;
+          _dest_statbuf.lastmod.tv_sec = stbuf.st_mtime;
           _dest_statbuf.lastmod.tv_nsec = 0;
-          _dest_statbuf.lastchange.tv_sec = stbuf.ctime;
+          _dest_statbuf.lastchange.tv_sec = stbuf.st_ctime;
           _dest_statbuf.lastchange.tv_nsec = 0;
 #endif
           _dest_statbuf.mode = stbuf.st_mode;
