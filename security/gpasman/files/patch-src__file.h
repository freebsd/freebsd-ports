--- src/file.h.orig	Sun Nov 13 16:14:11 2005
+++ src/file.h	Sun Nov 13 16:14:19 2005
@@ -7,6 +7,8 @@
  * 4 = comment
  */
 
+#include <sys/types.h>
+
 int save_init(char *filename, char *password);
 int save_entry(char *entry[4]);
 int save_finalize(void);
