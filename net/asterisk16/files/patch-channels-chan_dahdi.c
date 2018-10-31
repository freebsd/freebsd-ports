--- channels/chan_dahdi.c.orig	2018-08-08 16:02:31 UTC
+++ channels/chan_dahdi.c
@@ -4599,6 +4599,8 @@ void dahdi_ec_enable(struct dahdi_pvt *p)
 		return;
 	}
 	if (p->echocancel.head.tap_length) {
+		struct dahdi_echocanparams *pecp;
+
 #if defined(HAVE_PRI) || defined(HAVE_SS7)
 		switch (p->sig) {
 #if defined(HAVE_PRI)
@@ -4629,7 +4631,9 @@ void dahdi_ec_enable(struct dahdi_pvt *p)
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
@@ -4663,8 +4667,9 @@ void dahdi_ec_disable(struct dahdi_pvt *p)
 
 	if (p->echocanon) {
 		struct dahdi_echocanparams ecp = { .tap_length = 0 };
+		struct dahdi_echocanparams *pecp = &ecp;
 
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &ecp);
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 
 		if (res)
 			ast_log(LOG_WARNING, "Unable to disable echo cancellation on channel %d: %s\n", p->channel, strerror(errno));
