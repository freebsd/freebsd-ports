
$FreeBSD$

--- plugins/mailWizard/mailWizard.c	2001/12/11 15:18:13	1.1
+++ plugins/mailWizard/mailWizard.c	2001/12/11 15:18:27
@@ -1,8 +1,8 @@
 #include <config.h>
 
+#include <sys/types.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
-#include <sys/types.h>
 #include <sys/socket.h> 
 #include <sys/stat.h>
 #include <unistd.h>
