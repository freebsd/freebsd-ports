--- include/platform.h.orig	Thu Mar 20 08:57:01 2003
+++ include/platform.h	Fri Mar 21 10:34:00 2003
@@ -33,7 +33,7 @@
   It enables tidy to find config files named ~/.tidyrc if 
   the HTML_TIDY environment variable is not set.
 */
-/* #define USER_CONFIG_FILE "~/.tidyrc" */
+#define USER_CONFIG_FILE "~/.tidyrc"
 
 /*
   Uncomment the following #define if your
@@ -48,7 +48,7 @@
   Contributed by Todd Lewis.
 */
 
-/* #define SUPPORT_GETPWNAM */
+#define SUPPORT_GETPWNAM
 
 
 /* Enable/disable support for Big5 and Shift_JIS character encodings */
@@ -443,16 +443,14 @@
 /* hack for gnu sys/types.h file  which defines uint and ulong */
 /* you may need to delete the #ifndef and #endif on your system */
 
-#ifndef __USE_MISC
 #if defined(BE_OS) || defined(SOLARIS_OS) || defined(BSD_BASED_OS) || defined(MAC_OS_X) || defined(OSF_OS) || defined(IRIX_OS) || defined(AIX_OS)
 #include <sys/types.h>
+typedef unsigned long ulong;
 #else
 #if !defined(HPUX_OS) && !defined(CYGWIN_OS)
 typedef unsigned int uint;
 #endif
-typedef unsigned long ulong;
 #endif
-#endif /* __USE_MISC */
 
 #ifndef TIDY_EXPORT /* Define it away for most builds */
 #define TIDY_EXPORT
