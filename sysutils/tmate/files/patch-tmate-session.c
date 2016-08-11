--- tmate-session.c.orig	2016-03-29 03:30:07 UTC
+++ tmate-session.c
@@ -8,6 +8,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
+#include <netinet/in.h>
 
 #include "tmate.h"
 
