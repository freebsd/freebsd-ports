--- wordlist.c.orig	2014-11-11 14:41:25 UTC
+++ wordlist.c
@@ -10,11 +10,6 @@
  * There's ABSOLUTELY NO WARRANTY, express or implied.
  */
 
-/* NOTE, _POSIX_SOURCE fuk's up solaris 32 bit 64 bit processing!!! */
-#ifndef sparc
-#define _POSIX_SOURCE /* for fileno(3) */
-#endif
-
 #include <stdio.h>
 #include <sys/stat.h>
 
