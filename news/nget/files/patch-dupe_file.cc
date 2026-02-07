--- dupe_file.cc	2004-05-29 16:00:05.000000000 -0700
+++ dupe_file.cc	2008-03-02 23:03:01.000000000 -0800
@@ -25,6 +25,7 @@
 #include <sys/stat.h>
 #include <unistd.h>
 #include <errno.h>
+#include <string.h>
 
 void dupe_file_checker::add(const char *filename, ulong size){
 	file_match *fm;
