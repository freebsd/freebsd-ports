--- quota/report.c.orig	Tue Feb  7 21:24:32 2006
+++ quota/report.c	Tue Feb  7 21:25:12 2006
@@ -17,6 +17,7 @@
  */
 
 #include <xfs/command.h>
+#include <sys/types.h>
 #include <pwd.h>
 #include <grp.h>
 #include <utmp.h>
