--- channels/chan_dahdi.c.orig	2015-07-24 22:06:05 UTC
+++ channels/chan_dahdi.c
@@ -5030,6 +5030,8 @@ static void dahdi_enable_ec(struct dahdi
 		return;
 	}
 	if (p->echocancel.head.tap_length) {
+		struct dahdi_echocanparams *pecp;
+
 #if defined(HAVE_PRI) || defined(HAVE_SS7)
 		switch (p->sig) {
 #if defined(HAVE_PRI)
@@ -5060,7 +5062,9 @@ static void dahdi_enable_ec(struct dahdi
 			break;
 		}
 #endif	/* defined(HAVE_PRI) || defined(HAVE_SS7) */
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &p->echocancel);
+
+		pecp = &p->echocancel.head;
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 		if (res) {
 			ast_log(LOG_WARNING, "Unable to enable echo cancellation on channel %d (%s)\n", p->channel, strerror(errno));
 		} else {
@@ -5094,8 +5098,9 @@ static void dahdi_disable_ec(struct dahd
 
 	if (p->echocanon) {
 		struct dahdi_echocanparams ecp = { .tap_length = 0 };
+		struct dahdi_echocanparams *pecp = &ecp;
 
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &ecp);
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 
 		if (res)
 			ast_log(LOG_WARNING, "Unable to disable echo cancellation on channel %d: %s\n", p->channel, strerror(errno));
