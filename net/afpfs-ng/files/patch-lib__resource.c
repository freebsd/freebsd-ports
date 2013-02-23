--- lib/resource.c.orig	2008-02-18 03:46:56.000000000 +0000
+++ lib/resource.c	2012-10-14 13:11:34.000000000 +0000
@@ -3,11 +3,11 @@
 #include <string.h>
 #include <errno.h>
 #include <fcntl.h>
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 #include "resource.h"
 #include "lowlevel.h"
 #include "did.h"
-#include "midlevel.h"
+#include "afpfs-ng/midlevel.h"
 
 #define appledouble ".AppleDouble"
 #define finderinfo_string ".finderinfo"
diff -Naur afpfs-ng-0.8.1.orig/lib/server.c afpfs-ng-0.8.1/lib/server.c
