--- src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c.orig	2014-02-10 16:16:55.000000000 -0600
+++ src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c	2014-02-27 08:10:17.000000000 -0600
@@ -57,6 +57,8 @@
 
 #include "src/slurmd/slurmd/slurmd.h"
 
+#include <limits.h>
+
 
 /***************************************************************/
 
