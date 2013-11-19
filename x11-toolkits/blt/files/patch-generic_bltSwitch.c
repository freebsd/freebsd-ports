--- generic/bltSwitch.c.orig	2013-11-18 17:14:04.000000000 +0100
+++ generic/bltSwitch.c	2013-11-18 17:14:37.000000000 +0100
@@ -111,7 +111,7 @@
             if (specPtr->switchName == NULL) {
                 continue;
             }
-            if (name[1] != '?' || specPtr->type < 0 || specPtr->type >= BLT_SWITCH_END) {
+            if (name[1] != '?' || specPtr->type == 0 || specPtr->type >= BLT_SWITCH_END) {
                 Tcl_AppendResult(interp, specPtr->switchName, " ", 0);
             } else {
                 static char *typenames[BLT_SWITCH_END+10] = {
