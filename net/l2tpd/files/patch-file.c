
$FreeBSD$

--- file.c.orig	Sat Aug 10 03:55:14 2002
+++ file.c	Wed Apr 16 16:07:19 2003
@@ -18,10 +18,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <netdb.h>
-#include <netinet/in.h>
 #include <time.h>
-#include <sys/types.h>
-#include <sys/socket.h>
 
 #include "l2tp.h"
 
@@ -207,6 +204,29 @@
     return 0;
 }
 
+int set_address (char *word, char *value, int context, void *item)
+{
+    switch (context & ~CONTEXT_DEFAULT)
+    {
+    case CONTEXT_GLOBAL:
+#ifdef DEBUG_FILE
+        log (LOG_DEBUG, "set_address: Setting global IP address to %s\n",
+             value);
+#endif
+	if (!inet_aton(value, &(((struct global *) item)->addr)))
+	{
+	    snprintf (filerr, sizeof (filerr), "invalid address given\n");
+	    return -1;
+	}
+        break;
+    default:
+        snprintf (filerr, sizeof (filerr), "'%s' not valid in this context\n",
+                  word);
+        return -1;
+    }
+    return 0;
+}
+
 int set_port (char *word, char *value, int context, void *item)
 {
     switch (context & ~CONTEXT_DEFAULT)
@@ -1196,6 +1216,7 @@
 }
 
 struct keyword words[] = {
+    {"address", &set_address},
     {"port", &set_port},
     {"rand source", &set_rand_source},
     {"auth file", &set_authfile},
