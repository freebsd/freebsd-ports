--- lease.c.orig	Thu Jan 26 07:48:28 2006
+++ lease.c	Thu Jun  8 22:05:22 2006
@@ -33,6 +33,16 @@
 #include <string.h>
 #include <sys/socket.h>
 #include <sys/queue.h>
+#if TIME_WITH_SYS_TIME
+# include <sys/time.h>
+# include <time.h>
+#else
+# if HAVE_SYS_TIME_H
+#  include <sys/time.h>
+# else
+#  include <time.h>
+# endif
+#endif
 #include <netinet/in.h>
 #include "dhcp6.h"
 #include "config.h"
@@ -45,7 +55,7 @@
 
 struct hash_entry {
 	LIST_ENTRY(hash_entry) list;
-	char val[];
+	char *val;
 };
 
 LIST_HEAD(hash_head, hash_entry);
