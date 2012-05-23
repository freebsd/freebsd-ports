--- src/engine.c.orig	2011-10-12 07:47:52.000000000 +0900
+++ src/engine.c	2012-05-15 04:22:54.000000000 +0900
@@ -30,7 +30,7 @@
 #include <errno.h>
 #include <unistd.h>
 
-#include <glib/gthread.h>
+#include <glib.h>
 
 #include "engine.h"
 #include "ui.h"
