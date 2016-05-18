--- src/tpm_mgmt/tpm_nvread.c.orig	2011-08-17 12:20:35 UTC
+++ src/tpm_mgmt/tpm_nvread.c
@@ -19,6 +19,7 @@
  * http://www.opensource.org/licenses/cpl1.0.php.
  */
 
+#include <sys/stat.h>
 #include <limits.h>
 #include <ctype.h>
 #include <fcntl.h>
