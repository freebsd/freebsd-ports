--- lib/afp_internal.h.orig	2007-11-09 04:27:20.000000000 +0000
+++ lib/afp_internal.h	2012-10-14 13:11:34.000000000 +0000
@@ -1,7 +1,7 @@
 #ifndef _AFP_INTERNAL_H_
 #define _AFP_INTERNAL_H_
 
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 
 extern struct afp_versions afp_versions[];
 
diff -Naur afpfs-ng-0.8.1.orig/lib/afp_url.c afpfs-ng-0.8.1/lib/afp_url.c
