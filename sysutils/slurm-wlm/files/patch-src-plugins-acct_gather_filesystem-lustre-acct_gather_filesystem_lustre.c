--- src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c.orig	2015-04-23 22:50:47 UTC
+++ src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c
@@ -57,6 +57,8 @@
 
 #include "src/slurmd/slurmd/slurmd.h"
 
+#include <limits.h>
+
 
 /***************************************************************/
 
