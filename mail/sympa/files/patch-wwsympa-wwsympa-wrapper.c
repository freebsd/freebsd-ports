--- wwsympa/wwsympa-wrapper.c	Sat Oct 23 20:42:47 2004
+++ wwsympa/wwsympa-wrapper.c	Sat Oct 23 20:42:30 2004
@@ -0,0 +1,8 @@
+#include <unistd.h>
+
+#define WWSYMPA "/usr/local/sympa/bin/wwsympa.fcgi"
+
+int main(int argn, char **argv, char **envp) {
+    argv[0] = WWSYMPA;
+    execve(WWSYMPA,argv,envp);
+}
