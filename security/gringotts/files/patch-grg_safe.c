--- src/grg_safe.c.orig	Tue Feb 18 22:04:29 2003
+++ src/grg_safe.c	Tue Feb 18 22:05:27 2003
@@ -33,6 +33,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -43,7 +44,6 @@
 #include <sys/fsuid.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <sys/resource.h>
 
 #define GRG_SAFE			0
@@ -57,8 +57,6 @@
 grg_mlockall_and_drop_root_privileges (void)
 {
   //drop eventual group root privileges
-  setgid (getgid ());
-  setgid (getgid ());		//twice for counter "saved IDs", cfr. Secure Programming HowTo
 #ifdef HAVE_SYS_FSUID_H
   setfsgid (getgid ());
   setfsgid (getgid ());
@@ -82,8 +80,6 @@
 #endif
 
       //drop root privileges
-      setuid (getuid ());
-      setuid (getuid ());
 #ifdef HAVE_SYS_FSUID_H
       setfsuid (getuid ());
       setfsuid (getuid ());
