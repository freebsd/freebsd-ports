--- src/utility.c.orig	Sun Jun  9 09:58:43 2002
+++ src/utility.c	Thu Feb 13 09:56:06 2003
@@ -16,6 +16,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <stdio.h>
@@ -421,9 +422,9 @@
 unsigned char path_exist (char *path)
 {
   DIR *dir;
-  
   dir = opendir(path);
-  closedir(dir);
+  if (dir)
+    closedir(dir);
   return ( dir != NULL ) ? 1 : 0;
 }
 
