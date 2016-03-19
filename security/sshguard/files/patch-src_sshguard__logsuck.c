--- src/sshguard_logsuck.c.orig	2015-08-19 16:11:25 UTC
+++ src/sshguard_logsuck.c
@@ -92,8 +92,6 @@ int logsuck_add_logsource(const char *re
         return -1;
     }
 
-    sshguard_log(LOG_DEBUG, "Adding '%s' to polled files.", filename);
-
     /* store filename */
     strcpy(cursource.filename, filename);
 
@@ -185,7 +183,6 @@ int logsuck_getline(char *restrict buf, 
             }
         }
         /* no data. Wait for something with exponential backoff, up to LOGSUCK_MAX_WAIT */
-        sshguard_log(LOG_DEBUG, "Sleeping %d ms before next poll.", sleep_interval);
         usleep(sleep_interval * 1000);
         /* update sleep interval for next call */
         if (sleep_interval < MAX_LOGPOLL_INTERVAL) {
@@ -274,7 +271,6 @@ static int refresh_files() {
         ++numchanged;
         if (! myentry->active) {
             /* entry was inactive, now available. Resume it */
-            sshguard_log(LOG_NOTICE, "Source '%s' reappeared. Reloading.", myentry->filename);
         } else {
             /* rotated (ie myentry->current_serial_number != fileinfo.st_ino) */
             sshguard_log(LOG_NOTICE, "Reloading rotated file %s.", myentry->filename);
@@ -285,8 +281,6 @@ static int refresh_files() {
         /* descriptor and source ready! */
     }
     list_iterator_stop(& sources_list);
-
-    sshguard_log(LOG_INFO, "Refreshing sources showed %u changes.", numchanged);
     return 0;
 }
 
