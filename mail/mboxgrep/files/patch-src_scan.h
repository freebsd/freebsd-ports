--- src/scan.h.orig	2003-03-30 23:07:10 UTC
+++ src/scan.h
@@ -23,8 +23,7 @@
 
 #include "mboxgrep.h"
 
-void scan_mailbox (char path[]);
-void recursive_scan (char path[]);
-int md5_check_message (char *body, checksum_t *chksum);
+void scan_mailbox(const char path[]);
+void recursive_scan(const char path[]);
 
 #endif /* SCAN_H */
