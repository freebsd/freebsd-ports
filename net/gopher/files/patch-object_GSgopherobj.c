
$FreeBSD$

--- object/GSgopherobj.c.orig	Sun Aug 22 15:51:21 2004
+++ object/GSgopherobj.c	Sun Aug 22 15:51:30 2004
@@ -2003,7 +2003,7 @@
      case news:
      case unset:
      case unknown:
-     }
+     break;}
 
      if (serviceType == ftp) {
 	  if (!(doneflags & G_PATH)) {
