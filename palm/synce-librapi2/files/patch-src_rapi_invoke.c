--- src/rapi/invoke.c.orig	Fri Jan 26 01:58:51 2007
+++ src/rapi/invoke.c	Fri Jan 26 01:59:15 2007
@@ -1,6 +1,7 @@
 /* $Id: invoke.c 2355 2006-04-07 18:47:20Z voc $ */
 #include "rapi_api.h"
 #include "rapi_context.h"
+#include <sys/socket.h>
 #include <assert.h>
 #include <stdlib.h>
 
