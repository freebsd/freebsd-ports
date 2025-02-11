--- tag-list.c.orig	2025-02-05 15:23:28 UTC
+++ tag-list.c
@@ -1,3 +1,4 @@
+#include <errno.h>
 #include <stdio.h>
 #include <limits.h>
 #include <string.h>
@@ -80,8 +81,6 @@ void    tag_list_error_check(int list_size, const char
 void    tag_list_error_check(int list_size, const char *path)
 
 {
-    extern int  errno;
-    
     if ( list_size == -1 )
     {
 	fprintf(stderr, "Unable to read %s: %s\n", path, strerror(errno));
