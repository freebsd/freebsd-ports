--- lib/did.c.orig	2008-02-18 03:39:17.000000000 +0000
+++ lib/did.c	2012-10-14 13:11:44.000000000 +0000
@@ -9,8 +9,8 @@
 #include <string.h>
 #include <stdio.h>
 
-#include "afp.h"
-#include "afp_protocol.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/afp_protocol.h"
 
 #undef DID_CACHE_DISABLE
 
@@ -226,7 +226,7 @@
 
 
 	/* Go to the end of last known entry */
-	p=path+(p-copy);
+	p=(char *)path+(p-copy);
 	p2=p;
 
 	while ((p=strchr(p+1,'/'))) {
diff -Naur afpfs-ng-0.8.1.orig/lib/dsi.c afpfs-ng-0.8.1/lib/dsi.c
