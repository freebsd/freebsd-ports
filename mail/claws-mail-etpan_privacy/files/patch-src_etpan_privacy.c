--- src/etpan_privacy.c.orig	Tue Aug 28 20:35:27 2007
+++ src/etpan_privacy.c	Tue Aug 28 20:35:44 2007
@@ -35,7 +35,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/mman.h>
-#include <libetpan.h>
+#include <libetpan/libetpan.h>
 #include <limits.h>
 
 static struct mailprivacy * privacy = NULL;
