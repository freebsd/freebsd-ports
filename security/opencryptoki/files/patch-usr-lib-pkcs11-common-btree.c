--- usr/lib/pkcs11/common/btree.c.orig	2016-04-29 17:26:45 UTC
+++ usr/lib/pkcs11/common/btree.c
@@ -30,7 +30,7 @@
 
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "pkcs11types.h"
 #include "local_types.h"
