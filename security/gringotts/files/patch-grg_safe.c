--- src/grg_safe.c.orig	Sat Nov 23 18:42:36 2002
+++ src/grg_safe.c	Sat Nov 23 18:43:22 2002
@@ -33,6 +33,7 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -42,7 +43,6 @@
 #include <sys/fsuid.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <sys/resource.h>
 
 #define GRG_SAFE			0
@@ -56,8 +56,6 @@
 grg_mlockall_and_drop_root_privileges (void)
 {
   //drop eventual group root privileges
-  setgid (getgid ());
-  setgid (getgid ());		//twice for counter "saved IDs", cfr. Secure Programming HowTo
 #ifdef HAVE_SYS_FSUID_H
   setfsgid (getgid ());
   setfsgid (getgid ());
@@ -81,8 +79,6 @@
 #endif
 
       //drop root privileges
-      setuid (getuid ());
-      setuid (getuid ());
 #ifdef HAVE_SYS_FSUID_H
       setfsuid (getuid ());
       setfsuid (getuid ());
