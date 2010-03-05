--- channels/chan_dahdi.c.orig	2009-10-22 17:19:21.568250985 +0000
+++ channels/chan_dahdi.c	2009-10-22 17:26:26.261584076 +0000
@@ -1997,13 +1997,17 @@
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
 		if (res)  {
 			ast_log(LOG_WARNING, "Unable to enable echo cancellation on channel %d (%s)\n", p->channel, strerror(errno));
 		} else {
@@ -2037,8 +2041,9 @@
 
 	if (p->echocanon) {
 		struct dahdi_echocanparams ecp = { .tap_length = 0 };
+		struct dahdi_echocanparams *pecp = &ecp;
 
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &ecp);
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 
 		if (res)
 			ast_log(LOG_WARNING, "Unable to disable echo cancellation on channel %d: %s\n", p->channel, strerror(errno));
