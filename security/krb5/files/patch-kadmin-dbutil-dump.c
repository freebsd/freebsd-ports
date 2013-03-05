--- kadmin/dbutil/dump.c.orig	2013-02-21 15:23:19.000000000 -0800
+++ kadmin/dbutil/dump.c	2013-03-05 08:01:25.046422435 -0800
@@ -2973,6 +2973,20 @@
      */
     if (!(flags & FLAG_UPDATE)) {
         if (exit_status) {
+
+	/* Re-init ulog so we don't accidentally think we are current */
+	    if (log_ctx && log_ctx->iproprole) {
+		log_ctx->ulog->kdb_last_sno = 0;
+		log_ctx->ulog->kdb_last_time.seconds = 0;
+		log_ctx->ulog->kdb_last_time.useconds = 0;
+
+		log_ctx->ulog->kdb_first_sno = 0;
+		log_ctx->ulog->kdb_first_time.seconds = 0;
+		log_ctx->ulog->kdb_first_time.useconds = 0;
+
+		ulog_sync_header(log_ctx->ulog);
+	    }
+
             kret = krb5_db_destroy(kcontext, db5util_db_args);
             /*
              * Ignore a not supported error since there is nothing to do about
