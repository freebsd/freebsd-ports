--- include/sound.h.old	Thu Sep  2 23:34:10 1999
+++ include/sound.h	Thu Apr 11 08:32:05 2002
@@ -222,7 +222,11 @@
 #include <sys/types.h>
 #include <sys/file.h>
 #include <sys/stat.h>
+#if __FreeBSD__ > 3
+#include <sys/soundcard.h>
+#else
 #include <machine/soundcard.h>
+#endif
 
 #undef	O_RDWR
 #define	O_RDWR	O_WRONLY	/* audio デバイスは同時オープンできない？ */
