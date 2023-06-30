--- src/providers/proxy/proxy_child.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/proxy/proxy_child.c
@@ -30,6 +30,7 @@
 #include <sys/stat.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <stdlib.h>
 #include <string.h>
 #include <sys/time.h>
 #include <errno.h>
@@ -469,6 +470,18 @@ int proxy_child_process_init(TALLOC_CTX *mem_ctx, cons
 
     return EOK;
 }
+
+
+#if (defined(__FreeBSD__) && (__FreeBSD__ < 14))
+extern char **environ;
+
+static int
+clearenv(void)
+{
+    *environ = NULL;
+    return 0;
+}
+#endif
 
 int main(int argc, const char *argv[])
 {
