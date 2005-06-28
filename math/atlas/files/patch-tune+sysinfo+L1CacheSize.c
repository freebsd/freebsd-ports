--- tune/sysinfo/L1CacheSize.c	Mon Dec 22 23:11:53 2003
+++ ../../L1CacheSize.c	Tue Jun 28 13:37:10 2005
@@ -31,7 +31,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#define REPS 4096
+#define REPS 12288
 
 #ifndef time00
    #define time00 ATL_cputime
@@ -134,7 +134,7 @@
 
 main(int nargs, char *args[])
 {
-   int L1Size, tmp, MaxSize=64, correct=1;
+   int L1Size, tmp, MaxSize=256, correct=1;
    FILE *L1f;
 
    if (nargs > 2)
