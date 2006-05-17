--- lib/file/regular.cc.orig	Mon Jun 13 12:21:49 2005
+++ lib/file/regular.cc	Tue May 16 15:38:03 2006
@@ -29,6 +29,11 @@
 #include <fcntl.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/stat.h>
+#endif
+
 #include <careful.h>
 #include <cgi.h>
 #include <configuration.h>
@@ -386,7 +391,7 @@
     output_stdout op;
     op << "Content-Type: text/html\n"
           "Content-Length: "
-       << st.st_size
+       << (char)st.st_size
        << "\n"
           "\n";
     for (;;)
