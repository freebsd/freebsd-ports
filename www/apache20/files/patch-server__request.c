--- ./server/request.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./server/request.c	2010-10-21 05:40:53.653628850 +0000
@@ -1040,7 +1040,7 @@
                 continue;
             }
 
-            if (ap_regexec(entry_core->r, r->filename, 0, NULL, REG_NOTEOL)) {
+            if (ap_regexec(entry_core->r, r->filename, 0, NULL, AP_REG_NOTEOL)) {
                 continue;
             }
 
