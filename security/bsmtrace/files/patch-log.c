--- log.c.orig	2020-08-23 21:49:15 UTC
+++ log.c
@@ -31,6 +31,8 @@
 #include "includes.h"
 #undef SYSLOG_NAMES
 
+struct logchannel_head log_head;
+
 int
 log_bsm_syslog(struct logchannel *lc, struct bsm_sequence *bs,
     struct bsm_record_data *br);
