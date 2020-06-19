--- plugins/ssh/ssh.c.orig	2020-06-18 20:38:31 UTC
+++ plugins/ssh/ssh.c
@@ -30,6 +30,7 @@
  * SUCH DAMAGE.
  */
 
+#include <sys/stat.h>
 #include <config.h>
 
 #include <stdio.h>
