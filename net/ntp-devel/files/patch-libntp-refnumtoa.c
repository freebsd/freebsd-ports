--- libntp/refnumtoa.c.orig	2001-10-09 00:05:38.000000000 -0700
+++ libntp/refnumtoa.c	2008-07-24 22:45:30.917697416 -0700
@@ -2,6 +2,9 @@
  * refnumtoa - return asciized refclock addresses stored in local array space
  */
 #include <stdio.h>
+#ifdef __FreeBSD_cc_version
+#include <netinet/in.h>
+#endif
 
 #include "ntp_fp.h"
 #include "lib_strbuf.h"
