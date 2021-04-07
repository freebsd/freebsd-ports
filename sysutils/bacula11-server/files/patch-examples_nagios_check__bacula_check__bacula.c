--- examples/nagios/check_bacula/check_bacula.c.orig	2021-04-01 12:38:35 UTC
+++ examples/nagios/check_bacula/check_bacula.c
@@ -324,7 +324,7 @@ int docmd(monitoritem* item, const char* command, char
             continue;
          }
 
-        if (strncmp(item->D_sock, "Events:", strlen("Events:")) == 0) {
+        if (strncmp(item->D_sock->msg, "Events:", strlen("Events:")) == 0) {
            /* Daemons can send events to the director, ignore them here */
            continue;
         }
