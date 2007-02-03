--- include/platform.h.orig	Sun Jan 21 21:36:21 2007
+++ include/platform.h	Sat Feb  3 17:39:40 2007
@@ -33,7 +33,7 @@
   It enables tidy to find config files named ~/.tidyrc if 
   the HTML_TIDY environment variable is not set.
 */
-/* #define TIDY_USER_CONFIG_FILE "~/.tidyrc" */
+#define TIDY_USER_CONFIG_FILE "~/.tidyrc"
 
 /*
   Uncomment the following #define if your
@@ -48,7 +48,7 @@
   Contributed by Todd Lewis.
 */
 
-/* #define SUPPORT_GETPWNAM */
+#define SUPPORT_GETPWNAM
 
 
 /* Enable/disable support for Big5 and Shift_JIS character encodings */
