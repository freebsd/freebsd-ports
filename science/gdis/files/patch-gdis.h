--- gdis.h.orig	Tue Mar  5 11:24:15 2002
+++ gdis.h	Tue Mar  5 11:25:22 2002
@@ -61,7 +61,7 @@
 
 /* location of data file - TODO - IMPROVE ie rc file/scan etc */
 #define RCFILE ".gdisrc"
-#define LIBRARY "gdis.lib"
+#define LIBRARY "%%DATADIR%%gdis.lib"
 #define LOG_FILE "gdismol.log"
 #define FONT "-misc-fixed-medium-r-*-*-*-120-*-*-*-*-iso8859-1"
 
