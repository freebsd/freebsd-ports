--- rvt/command.c.orig	2008-02-27 22:29:48.000000000 +0300
+++ rvt/command.c	2011-09-29 18:18:07.000000000 +0400
@@ -41,7 +41,6 @@ char xvt_command_c_sccsid[] = "@(#)comma
 #include <unistd.h>
 #include <signal.h>
 #include <fcntl.h>
-#include <utmp.h>
 #include <errno.h>
 #include <string.h>
 #include "rvt.h"
