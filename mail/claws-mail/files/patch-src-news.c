--- src/news.c.orig	2013-06-02 14:53:22.000000000 +0200
+++ src/news.c	2013-06-02 14:51:55.000000000 +0200
@@ -56,6 +56,7 @@
 #include "remotefolder.h"
 #include "alertpanel.h"
 #include "inc.h"
+#include "account.h"
 #ifdef USE_GNUTLS
 #  include "ssl.h"
 #endif
