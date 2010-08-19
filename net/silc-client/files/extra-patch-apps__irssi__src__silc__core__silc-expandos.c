--- ./apps/irssi/src/silc/core/silc-expandos.c.orig	2010-08-16 09:37:26.000000000 -0400
+++ ./apps/irssi/src/silc/core/silc-expandos.c	2010-08-16 09:37:45.000000000 -0400
@@ -29,6 +29,7 @@
 #include "silc-channels.h"
 #include "silc-queries.h"
 #include "silc-nicklist.h"
+#include "silcdefs.h"
 
 EXPANDO_FUNC old_expando_usermode,
             old_expando_cumode,
