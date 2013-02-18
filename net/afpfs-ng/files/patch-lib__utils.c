--- lib/utils.c.orig	2008-02-18 03:53:37.000000000 +0000
+++ lib/utils.c	2012-10-14 13:11:44.000000000 +0000
@@ -8,10 +8,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
-#include "afp.h"
-#include "utils.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/utils.h"
 #include "afp_internal.h"
-#include "afp_protocol.h"
+#include "afpfs-ng/afp_protocol.h"
 
 struct afp_path_header_long {
 	unsigned char type;
@@ -196,7 +196,7 @@
 			maxlen=255;
 
 
-	p=filename+1;
+	p=(char *)filename+1;
 	while ((q=strchr(p,'/'))) {
 		if (q>p+maxlen)
 			return 1;
