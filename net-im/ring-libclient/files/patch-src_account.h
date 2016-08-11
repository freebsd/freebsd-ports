--- src/account.h.orig	2016-05-19 17:41:40 UTC
+++ src/account.h
@@ -24,6 +24,9 @@
 //Qt
 class QString;
 
+//FreeBSD
+#include <time.h>
+
 //Ring
 #include "itembase.h"
 #include "keyexchangemodel.h"
