--- src/grg_safe.c.orig	Sat Oct 26 14:09:40 2002
+++ src/grg_safe.c	Sat Oct 26 14:15:28 2002
@@ -34,6 +34,7 @@
 
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
@@ -64,8 +64,6 @@
 #endif
 
 	//drop eventual group root privileges
-	setgid(getgid ());
-	setgid(getgid ()); //twice for counter "saved IDs", cfr. Secure Programming HowTo
 #ifdef HAVE_SYS_FSUID_H
 	setfsgid(getgid ());
 	setfsgid(getgid ());
@@ -84,8 +82,6 @@
 #endif
 
 		//drop root privileges
-		setuid(getuid());
-		setuid(getuid());
 #ifdef HAVE_SYS_FSUID_H
 		setfsuid(getuid());
 		setfsuid(getuid());
