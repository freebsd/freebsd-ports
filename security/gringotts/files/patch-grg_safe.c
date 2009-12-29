--- src/grg_safe.c.orig	2008-01-04 22:08:43.000000000 +0900
+++ src/grg_safe.c	2009-12-22 04:53:36.000000000 +0900
@@ -33,6 +33,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <errno.h>
 #include <regex.h>
 #include <unistd.h>
@@ -44,7 +45,6 @@
 #include <sys/fsuid.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <sys/resource.h>
 #ifdef linux
 #include <sys/utsname.h>
@@ -96,9 +96,6 @@
 grg_mlockall_and_drop_root_privileges(void)
 {
     /* drop eventual group root privileges */
-    setgid(getgid());
-    setgid(getgid());		/* twice for counter "saved IDs", cfr. */
-				/* Secure Programming HowTo */
 #ifdef HAVE_SYS_FSUID_H
     setfsgid(getgid());
     setfsgid(getgid());
@@ -148,8 +145,6 @@
 #endif
 
 	/* drop root privileges */
-	setuid(getuid());
-	setuid(getuid());
 #ifdef HAVE_SYS_FSUID_H
 	setfsuid(getuid());
 	setfsuid(getuid());
