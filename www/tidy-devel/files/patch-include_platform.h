--- include/platform.h.orig	2008-03-17 12:57:01 UTC
+++ include/platform.h
@@ -33,7 +33,7 @@ extern "C" {
   It enables tidy to find config files named ~/.tidyrc if 
   the HTML_TIDY environment variable is not set.
 */
-/* #define TIDY_USER_CONFIG_FILE "~/.tidyrc" */
+#define TIDY_USER_CONFIG_FILE "~/.tidyrc"
 
 /*
   Uncomment the following #define if your
@@ -48,7 +48,7 @@ extern "C" {
   Contributed by Todd Lewis.
 */
 
-/* #define SUPPORT_GETPWNAM */
+#define SUPPORT_GETPWNAM
 
 
 /* Enable/disable support for Big5 and Shift_JIS character encodings */
