--- common/dispatch.c.orig	Sun Nov 17 03:26:57 2002
+++ common/dispatch.c	Wed Mar  3 16:20:15 2004
@@ -95,11 +95,26 @@
 void dispatch ()
 {
 	struct timeval tv, *tvp;
+#ifdef ENABLE_POLLING_MODE
+	struct timeval *tvp_new;
+#endif
 	isc_result_t status;
+	TIME cur_time;
 
+	tvp = NULL;
+#ifdef ENABLE_POLLING_MODE
+	tvp_new = NULL;
+#endif
 	/* Wait for a packet or a timeout... XXX */
 	do {
 		tvp = process_outstanding_timeouts (&tv);
+#ifdef ENABLE_POLLING_MODE
+		GET_TIME (&cur_time);
+		add_timeout(cur_time + polling_interval, state_polling, 0, 0, 0);
+		tvp_new = process_outstanding_timeouts(&tv);
+		if (tvp != NULL && (tvp -> tv_sec > tvp_new -> tv_sec))
+			tvp = tvp_new;
+#endif /* ENABLE_POLLING_MODE */
 		status = omapi_one_dispatch (0, tvp);
 	} while (status == ISC_R_TIMEDOUT || status == ISC_R_SUCCESS);
 	log_fatal ("omapi_one_dispatch failed: %s -- exiting.",
