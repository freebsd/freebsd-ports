--- sources/handlers.h.orig	Wed Oct 15 17:06:59 2003
+++ sources/handlers.h	Wed Oct 15 17:07:08 2003
@@ -19,6 +19,7 @@
 
 /* handlers.c */
 int cgiHandler();
+int phpHandler();
 int dumpHeader();
 int dumpFile();
 int generateIndex();
