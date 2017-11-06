--- object/GSgopherobj.c.orig	2003-08-18 16:58:58 UTC
+++ object/GSgopherobj.c
@@ -2003,7 +2003,7 @@ GSfromURL(GopherObj *gs, char *urltxt, c
      case news:
      case unset:
      case unknown:
-     }
+     break;}
 
      if (serviceType == ftp) {
 	  if (!(doneflags & G_PATH)) {
