--- saferpay/saferpay.c.orig	Tue Feb 18 16:51:58 2003
+++ saferpay/saferpay.c	Tue Feb 18 16:52:14 2003
@@ -3,7 +3,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "idpapi.h"
 #include "idperrc.h"
 
