--- panel-plugin/apmlib.c.orig	Thu Jul 31 09:34:47 2003
+++ panel-plugin/apmlib.c	Thu Jul 31 09:18:25 2003
@@ -18,6 +18,9 @@
  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  *
  */
+
+#if defined(__linux__)
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -463,3 +466,5 @@
 
     return buffer;
 }
+
+#endif
