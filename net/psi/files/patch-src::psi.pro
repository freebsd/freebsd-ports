$FreeBSD$

Disable the use of /bin/true (doesn't exist in FreeBSD)

--- src/psi.pro.orig	Wed Oct 30 23:09:34 2002
+++ src/psi.pro	Mon Nov  4 20:43:19 2002
@@ -157,7 +157,6 @@
 	LIBS         += -lz -lXss
 	SOURCES      += trayicon_x11.cpp
 
-	QMAKE_STRIP = "/bin/true"
 	include( configure.pri )
 }
 
