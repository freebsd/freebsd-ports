--- lib/hostname.cc.orig	Sun Aug 25 00:04:39 2002
+++ lib/hostname.cc	Sun Aug 25 00:06:23 2002
@@ -22,6 +22,7 @@
 #include "config.h"
 #include "mystring/mystring.h"
 #include <unistd.h>
+#include <string.h>
 #include <sys/utsname.h>
 
 static mystring* hostname_cache = 0;
@@ -30,7 +31,9 @@
 #ifdef HAVE_GETDOMAINNAME
 // Re-declare the prototype here, as some systems don't declare it
 // in a predictable header file.
+#if __FreeBSD_version > 500034
 extern "C" int getdomainname();
+#endif
 #endif
 
 static void getnames()
