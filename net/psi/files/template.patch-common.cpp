$FreeBSD$

--- src/common.cpp.orig	Wed May  1 22:06:07 2002
+++ src/common.cpp	Wed May  1 22:06:47 2002
@@ -1130,7 +1130,7 @@
 #ifdef Q_WS_X11
 QString getResourcesDir()
 {
-	return "/usr/local/psi";
+	return "%%DATADIR%%";
 }
 
 QString getHomeDir()
