--- support/acttimes.c	Tue Jan  9 08:28:02 1996
+++ support/acttimes.c	Mon Jun  4 09:40:37 2007
@@ -64,12 +64,6 @@
 
 /* ---------- End of configuration defines ---------- */
 
-#ifdef TERMIO
-#include <termio.h>
-#else
-#include <sgtty.h>
-#endif
-
 #define TIMER_FIRST 1
 #define TIMER_DEFAULT (10 * 60)
 
