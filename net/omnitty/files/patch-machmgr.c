--- machmgr.c.orig	2005-10-25 22:04:01 UTC
+++ machmgr.c
@@ -26,7 +26,7 @@
 #include "machine.h"
 #include "minibuf.h"
 #include <string.h>
-#include <alloca.h>
+#include <stdlib.h>
 
 #define MACHINE_MAX 256
 
@@ -261,5 +261,13 @@ void machmgr_delete_dead() {
    int i;
    for (i = machcount - 1; i >= 0; i--)
       if (!machs[i]->alive) machmgr_delete(i);
+}
+
+void machmgr_toggle_tag_all(bool ignore_dead) {
+   int i;
+   for (i = 0; i < machcount; i++) {
+      if (!ignore_dead || machs[i]->alive)
+	 machs[i]->tag = !machs[i]->tag;
+   }
 }
 
