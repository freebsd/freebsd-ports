--- usr/lib/common/btree.c.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/common/btree.c
@@ -18,7 +18,7 @@
 
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "pkcs11types.h"
 #include "local_types.h"
