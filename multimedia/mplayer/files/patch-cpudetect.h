--- cpudetect.h.orig	Sun Apr  6 01:28:52 2003
+++ cpudetect.h	Sun Apr  6 01:29:06 2003
@@ -5,6 +5,8 @@
 #define CPUTYPE_I486	4
 #define CPUTYPE_I586	5
 #define CPUTYPE_I686    6
+#define CPUTYPE_I686_7	7
+#define CPUTYPE_I686_8	8
 
 typedef struct cpucaps_s {
 	int cpuType;
