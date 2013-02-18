--- lib/codepage.c.orig	2008-02-18 03:36:54.000000000 +0000
+++ lib/codepage.c	2012-10-14 13:11:34.000000000 +0000
@@ -14,8 +14,8 @@
 
 #include <string.h>
 #include <stdlib.h>
-#include "afp_protocol.h"
-#include "utils.h"
+#include "afpfs-ng/afp_protocol.h"
+#include "afpfs-ng/utils.h"
 #include "unicode.h"
 
 int convert_utf8dec_to_utf8pre(const char *src, int src_len,
diff -Naur afpfs-ng-0.8.1.orig/lib/connect.c afpfs-ng-0.8.1/lib/connect.c
