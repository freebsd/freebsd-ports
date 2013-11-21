--- ./src/nfsping.c.orig	2013-11-21 09:36:28.914158570 -0600
+++ ./src/nfsping.c	2013-11-21 09:36:58.050495553 -0600
@@ -84,9 +84,9 @@
         printf("%s : [%u], %03.2f ms (%03.2f avg, %.0f%% loss)\n", target->name, target->sent - 1, us / 1000.0, target->avg / 1000.0, loss);
     } else if (format == graphite) {
         if (prognum == MOUNTPROG) {
-            printf("%s.%s.mount.usec %lu %li\n", prefix, target->ndqf, us, now.tv_sec);
+            printf("%s.%s.mount.usec %lu %li\n", prefix, target->ndqf, us, (long)now.tv_sec);
         } else {
-            printf("%s.%s.ping.usec %lu %li\n", prefix, target->ndqf, us, now.tv_sec);
+            printf("%s.%s.ping.usec %lu %li\n", prefix, target->ndqf, us, (long)now.tv_sec);
         }
     }
 }
@@ -96,7 +96,7 @@
     /* send to stdout even though it could be considered an error, presumably these are being piped somewhere */
     /* stderr prints the errors themselves which can be discarded */
     if (format == graphite) {
-        printf("%s.%s.ping.lost 1 %li\n", prefix, target->name, now.tv_sec);
+        printf("%s.%s.ping.lost 1 %li\n", prefix, target->name, (long)now.tv_sec);
     }
 }
 
