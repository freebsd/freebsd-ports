--- mpid/ch2/chtick.c-orig	Wed Apr  4 09:16:05 2001
+++ mpid/ch2/chtick.c	Sat Aug 25 08:49:10 2001
@@ -14,6 +14,7 @@
       !defined(MPID_CH_Wtime)
 #define USING_POSIX_CLOCK
 #include <time.h>
+#include <sys/time.h>
 #endif
 /* 
    This returns a value that is correct but not the best value that
