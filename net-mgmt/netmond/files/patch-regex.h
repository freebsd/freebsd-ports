--- regex.h.orig	Mon Feb 24 14:39:49 2003
+++ regex.h	Thu Nov  2 13:38:39 2006
@@ -21,12 +21,12 @@
  */
 #define MAXDFA  1024
 #define MAXTAG  10
-#define MAXCHR	128
+#define MAXCHR	256
 #define CHRBIT	8
 #define BITBLK	MAXCHR/CHRBIT
 #define BLKIND	0170
 #define BITIND	07
-#define ASCIIB	0177
+#define ASCIIB	0255
 
 typedef /*unsigned*/ char CHAR;
 
