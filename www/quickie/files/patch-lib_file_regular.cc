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
@@ -384,11 +389,8 @@
 	return;
     }
     output_stdout op;
-    op << "Content-Type: text/html\n"
-          "Content-Length: "
-       << st.st_size
-       << "\n"
-          "\n";
+    op << "Content-Type: text/html\n";
+    op.printf("Content-Length: %llu\n\n", st.st_size);
     for (;;)
     {
 	char buffer[1 << 14];

