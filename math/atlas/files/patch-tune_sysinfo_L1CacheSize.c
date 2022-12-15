--- tune/sysinfo/L1CacheSize.c.orig	2016-07-28 19:43:20 UTC
+++ tune/sysinfo/L1CacheSize.c
@@ -31,7 +31,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#define REPS 4096
+#define REPS 12288
 
 #ifndef time00
    #define time00 ATL_cputime
@@ -267,7 +267,7 @@ int main(int nargs, char *args[])
 
 int main(int nargs, char *args[])
 {
-   int L1Size, MaxSize=64, correct=1;
+   int L1Size, MaxSize=256, correct=1;
    FILE *L1f;
 
    if (nargs > 2)
