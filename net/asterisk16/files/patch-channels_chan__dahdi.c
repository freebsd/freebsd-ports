--- channels/chan_dahdi.c.orig	2020-07-09 15:39:17 UTC
+++ channels/chan_dahdi.c
@@ -4649,6 +4649,8 @@ void dahdi_ec_enable(struct dahdi_pvt *p)
 		return;
 	}
 	if (p->echocancel.head.tap_length) {
+		struct dahdi_echocanparams *pecp;
+
 #if defined(HAVE_PRI) || defined(HAVE_SS7)
 		switch (p->sig) {
 #if defined(HAVE_PRI)
@@ -4679,7 +4681,9 @@ void dahdi_ec_enable(struct dahdi_pvt *p)
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
@@ -4713,8 +4717,9 @@ void dahdi_ec_disable(struct dahdi_pvt *p)
 
 	if (p->echocanon) {
 		struct dahdi_echocanparams ecp = { .tap_length = 0 };
+		struct dahdi_echocanparams *pecp = &ecp;
 
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &ecp);
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 
 		if (res)
 			ast_log(LOG_WARNING, "Unable to disable echo cancellation on channel %d: %s\n", p->channel, strerror(errno));
