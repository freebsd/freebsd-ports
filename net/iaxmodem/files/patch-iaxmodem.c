--- iaxmodem.c.orig	2007-10-06 12:22:04.000000000 -0400
+++ iaxmodem.c	2007-11-06 23:54:40.000000000 -0500
@@ -21,17 +21,18 @@
 #include <string.h>
 #include <strings.h>
 
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 # ifndef USE_UNIX98_PTY
 #  include <pty.h>
 # endif /* !USE_UNIX98_PTY */
 #else
+#include <termios.h>
+#if !defined(__FreeBSD__)
 # include <util.h>
 #endif
+#endif
 
 
-#include <termios.h>
-
 #include <stdlib.h>
 #include <unistd.h>
 #include <dirent.h>
@@ -53,6 +54,26 @@
 #include <math.h>
 
 #include <stdint.h>
+
+#ifdef __FreeBSD__
+#include <libutil.h>
+char* strndup(const char* string, size_t n)
+{
+        char* copy_string = 0;
+
+        if(0 == string || 0 == n)
+                return 0;
+
+        copy_string = (char*) malloc(n + 1);
+        if(0 == copy_string)
+                return 0;
+
+        memcpy(copy_string, string, n);
+        *(copy_string + n) = '\0';
+
+        return copy_string;
+}
+#endif
 #include <tiffio.h>
 
 #ifndef O_LARGEFILE
@@ -1645,8 +1666,6 @@
 	}
       }
 
-    closedir(cfdir);
-
     if (pid == 0) {
       /* Start the modem */
       iaxmodem(config, 0);
@@ -1654,6 +1673,8 @@
       return 1;
     }
 
+    closedir(cfdir);
+
     return 0;
 }
