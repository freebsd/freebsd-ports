--- libempathy/empathy-auth-factory.c.orig	2011-12-07 17:19:17.000000000 +0000
+++ libempathy/empathy-auth-factory.c	2011-12-07 17:19:45.000000000 +0000
@@ -23,6 +23,7 @@
 #include <telepathy-glib/interfaces.h>
 #include <telepathy-glib/simple-handler.h>
 #include <telepathy-glib/util.h>
+#include <telepathy-glib/channel-dispatch-operation.h>
 
 #define DEBUG_FLAG EMPATHY_DEBUG_TLS
 #include "empathy-debug.h"
