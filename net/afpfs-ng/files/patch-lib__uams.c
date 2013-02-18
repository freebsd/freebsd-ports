--- lib/uams.c.orig	2008-01-04 03:52:44.000000000 +0000
+++ lib/uams.c	2012-10-14 13:11:44.000000000 +0000
@@ -8,10 +8,10 @@
 
 #include <string.h>
 #include <stdlib.h>
-#include "dsi.h"
-#include "afp.h"
-#include "utils.h"
-#include "uams_def.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/utils.h"
+#include "afpfs-ng/uams_def.h"
 #include "config.h"
 
 #ifdef HAVE_LIBGCRYPT
@@ -180,7 +180,7 @@
 		goto cleartxt_fail;
 
 	p += copy_to_pascal(p, username) + 1;
-	if ((int)p & 0x1)
+	if ((long)p & 0x1)
 		len--;
 	else
 		p++;
@@ -230,7 +230,7 @@
 		goto cleartxt_fail;
 
 	p += copy_to_pascal(p, username) + 1;
-	if ((int)p & 0x1)
+	if ((long)p & 0x1)
 		len--;
 	else
 		p++;
@@ -580,7 +580,7 @@
 	if (ai == NULL)
 		goto dhx_noctx_fail;
 	d += copy_to_pascal(ai, username) + 1;
-	if (((int)d) % 2)
+	if (((long)d) % 2)
 		d++;
 	else
 		ai_len--;
diff -Naur afpfs-ng-0.8.1.orig/lib/users.c afpfs-ng-0.8.1/lib/users.c
