--- src/speaker.c.orig	Mon Nov 17 21:47:38 2003
+++ src/speaker.c	Sun Mar 14 00:15:30 2004
@@ -31,16 +31,29 @@
  * $Id: stumbler.c,v 1.5 2003/11/14 15:54:29 pancake Exp $
  */
 
+#ifdef __FreeBSD__
+#ifdef __i386__
+#define _HAVE_SPEAKER
+#endif
+#elif __NetBSD__
+#define _HAVE_SPEAKER
+#endif
+
+
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
 #ifdef __FreeBSD__
+#ifdef _HAVE_SPEAKER
 #include <machine/speaker.h>
+#endif
 #else
 #include <machine/spkr.h>
 #endif
 
+#ifdef _HAVE_SPEAKER
+
 #define SPKR_DEV "/dev/speaker"
 #define SPKR_SPD "L08"
 
@@ -100,4 +113,8 @@
 	//}
 	fclose(fd);
 }
-
+#else
+	/* no speaker support */
+void swap_beep(void) {}
+void do_beep(int pc) {}
+#endif
