--- rvt/ttyinit.c.orig	2007-01-24 22:02:10.000000000 +0300
+++ rvt/ttyinit.c	2011-09-29 18:18:19.000000000 +0400
@@ -41,7 +41,6 @@ char xvt_ttyinit_c_sccsid[] = "@(#)ttyin
 #include <unistd.h>
 #include <signal.h>
 #include <fcntl.h>
-#include <utmp.h>
 #include <grp.h>
 #include <pwd.h>
 #include <errno.h>
