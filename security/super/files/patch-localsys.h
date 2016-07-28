--- localsys.h.orig	2007-12-20 19:14:53 UTC
+++ localsys.h
@@ -16,14 +16,14 @@
 #ifndef LOCALSYS_H
 #define LOCALSYS_H
 
-#include "config.h"
-
 #include <stdio.h>
 #include <ctype.h>
 #include <fcntl.h>
 #include <pwd.h>
 #include <grp.h>
 
+#include "config.h"
+
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
@@ -293,9 +293,11 @@ extern int sysinfo();
 #include <unistd.h>
 #endif
 
+#ifndef __FreeBSD__	/* FBSD has a malloc.h that tells people to obey C89. */
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
 #endif
+#endif
 
 #ifdef HAVE_SYSLOG_H
 #include <syslog.h>
