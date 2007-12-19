--- tune/sysinfo/L1CacheSize.c.orig	Tue Dec 19 06:48:02 2006
+++ tune/sysinfo/L1CacheSize.c	Wed Dec 27 12:43:59 2006
@@ -31,7 +31,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#define REPS 4096
+#define REPS 12288
 
 #ifndef time00
    #define time00 ATL_cputime
@@ -267,7 +267,7 @@
 
 main(int nargs, char *args[])
 {
-   int L1Size, MaxSize=64, correct=1;
+   int L1Size, MaxSize=256, correct=1;
    FILE *L1f;
 
    if (nargs > 2)
