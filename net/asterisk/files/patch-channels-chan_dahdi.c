--- channels/chan_dahdi.c.orig	2010-11-09 11:18:39.000000000 +0100
+++ channels/chan_dahdi.c	2010-11-09 11:22:15.000000000 +0100
@@ -4688,6 +4688,8 @@
 		return;
 	}
 	if (p->echocancel.head.tap_length) {
+		struct dahdi_echocanparams *pecp;
+
 #if defined(HAVE_PRI) || defined(HAVE_SS7)
 		switch (p->sig) {
 #if defined(HAVE_PRI)
@@ -4718,7 +4720,9 @@
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
@@ -4752,8 +4756,9 @@
 
 	if (p->echocanon) {
 		struct dahdi_echocanparams ecp = { .tap_length = 0 };
+		struct dahdi_echocanparams *pecp = &ecp;
 
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &ecp);
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 
 		if (res)
 			ast_log(LOG_WARNING, "Unable to disable echo cancellation on channel %d: %s\n", p->channel, strerror(errno));
