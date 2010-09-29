--- channels/chan_dahdi.c.orig	2010-05-05 17:50:15.000000000 +0600
+++ channels/chan_dahdi.c	2010-05-05 17:50:09.000000000 +0600
@@ -2672,13 +2672,17 @@
 		return;
 	}
 	if (p->echocancel.head.tap_length) {
+		struct dahdi_echocanparams *pecp;
+
 		if ((p->sig == SIG_BRI) || (p->sig == SIG_BRI_PTMP) || (p->sig == SIG_PRI) || (p->sig == SIG_SS7)) {
 			x = 1;
 			res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_AUDIOMODE, &x);
 			if (res)
 				ast_log(LOG_WARNING, "Unable to enable audio mode on channel %d (%s)\n", p->channel, strerror(errno));
 		}
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &p->echocancel);
+		
+		pecp = &p->echocancel.head;
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 		if (res) {
 			ast_log(LOG_WARNING, "Unable to enable echo cancellation on channel %d (%s)\n", p->channel, strerror(errno));
 		} else {
@@ -2712,8 +2716,9 @@
 
 	if (p->echocanon) {
 		struct dahdi_echocanparams ecp = { .tap_length = 0 };
+		struct dahdi_echocanparams *pecp = &ecp;
 
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &ecp);
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 
 		if (res)
 			ast_log(LOG_WARNING, "Unable to disable echo cancellation on channel %d: %s\n", p->channel, strerror(errno));
