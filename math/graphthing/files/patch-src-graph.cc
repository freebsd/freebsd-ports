--- src/graph.cc.orig	Sun Mar 23 23:55:29 2003
+++ src/graph.cc	Sun Mar 23 23:58:26 2003
@@ -96,7 +96,7 @@
 	/* We don't want anything skipped */
 #ifdef USING_FREEBSD
 #include <osreldate.h>
-#if __FreeBSD_verson >= 500035
+#if __FreeBSD_version >= 500035
 	fs.setf (std::ios_base::fmtflags (0));
 #else
 	fs.setf (0);
