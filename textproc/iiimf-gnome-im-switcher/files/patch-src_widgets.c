--- src/widgets.c.orig	Fri Sep 10 16:41:33 2004
+++ src/widgets.c	Fri Sep 10 16:42:03 2004
@@ -29,7 +29,7 @@
 #include <gnome.h>
 
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 
 #include "gnome-im-switcher.h"
 #include "widgets.h"
