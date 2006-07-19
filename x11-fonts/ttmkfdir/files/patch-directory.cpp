--- directory.cpp.orig	Mon Dec  9 11:29:11 2002
+++ directory.cpp	Wed Jul 19 11:41:32 2006
@@ -1,7 +1,9 @@
 #include <cctype>
 #include <dirent.h>
+#include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
+#include <fcntl.h>
 
 #include "directory.h"
 
@@ -37,19 +39,24 @@
 bool
 ttfdirectory::select (const char *name) const
 {
-    int len;
+    int fd;
+    unsigned int n;
     struct stat buf;
+    char sigdata[8];
+    char TTsig[] = "\000\001\000\000\000", OTsig[] = "OTTO";
 
     /* must be a regular file */
     if (::stat (name, &buf) || !(S_ISREG (buf.st_mode))) {
 	return false;
     }
-    
-    /* we make the decision by the extension of the file name */
-    return (((len = strlen (name)) > 4) &&
-	    (name[len - 4] == '.') &&
-	    (std::toupper(name[len - 3]) == 'T') &&
-	    (std::toupper(name[len - 2]) == 'T') &&
-	    ((std::toupper(name[len - 1]) == 'F') ||
-	     (std::toupper(name[len - 1]) == 'C')));
+
+    fd = ::open(name, O_RDONLY);
+    if (fd < 0) return false;
+    n = read(fd, sigdata, sizeof(sigdata));
+    close(fd);
+    if (n < sizeof(sigdata))
+       return false;
+                                                                               
+    return (!memcmp(sigdata, TTsig, 5)
+           || !memcmp(sigdata, OTsig, 4));
 }
