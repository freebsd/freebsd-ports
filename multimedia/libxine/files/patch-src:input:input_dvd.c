--- src/input/input_dvd.c.orig	Sat Jan 11 23:47:08 2003
+++ src/input/input_dvd.c	Sat Jan 11 23:48:51 2003
@@ -41,6 +41,7 @@
 #include <stdlib.h>
 #include <stddef.h>
 #include <dirent.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -132,6 +133,9 @@
 /* Array to hold MRLs returned by get_autoplay_list */
 #define MAX_DIR_ENTRIES 1250
 #define MAX_STR_LEN     255  
+
+#define off64_t off_t
+#define lseek64 lseek
 
 typedef struct {
   input_plugin_t    input_plugin; /* Parent input plugin type        */
