--- include/platform.h.orig	Mon Mar 31 09:57:04 2003
+++ include/platform.h	Mon Mar 31 21:23:33 2003
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
