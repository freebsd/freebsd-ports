--- compat/adjfreq_freebsd.c.orig	2015-03-12 04:42:13 UTC
+++ compat/adjfreq_freebsd.c
@@ -57,3 +57,20 @@ adjfreq(const int64_t *freq, int64_t *ol
 
 	return 0;
 }
+
+/*
+ * The RTC is only updated if the clock is not marked as unsynced.
+ */
+
+void
+update_status(int synced)
+{
+	struct timex txc = { 0 };
+
+	txc.modes = MOD_STATUS;
+	if (!synced)
+		txc.status = STA_UNSYNC;
+	if (ntp_adjtime(&txc) == -1)
+		log_warn("ntp_adjtime (3) failed");
+	return;
+}
