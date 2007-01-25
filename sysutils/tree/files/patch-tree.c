--- tree.c.orig	Tue Jan  9 23:07:16 2007
+++ tree.c	Thu Jan 25 18:58:28 2007
@@ -17,7 +17,6 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
-#include <features.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
@@ -178,12 +177,6 @@
 char *sLevel, *curdir, *outfilename = NULL;
 FILE *outfile;
 int *dirs, maxdirs;
-
-#ifdef CYGWIN
-extern int MB_CUR_MAX;
-#else
-extern size_t MB_CUR_MAX;
-#endif
 
 int main(int argc, char **argv)
 {
