--- saferpay/saferpay.c.orig	Tue Jan  6 15:12:14 2004
+++ saferpay/saferpay.c	Tue Jan  6 15:12:28 2004
@@ -3,7 +3,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "idpapi.h"
 #include "idperrc.h"
 
