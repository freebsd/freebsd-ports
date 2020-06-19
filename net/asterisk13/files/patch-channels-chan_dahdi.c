--- channels/chan_dahdi.c.orig	2020-06-11 08:42:48 UTC
+++ channels/chan_dahdi.c
@@ -4716,6 +4716,8 @@ void dahdi_ec_enable(struct dahdi_pvt *p)
 		return;
 	}
 	if (p->echocancel.head.tap_length) {
+		struct dahdi_echocanparams *pecp;
+
 #if defined(HAVE_PRI) || defined(HAVE_SS7)
 		switch (p->sig) {
 #if defined(HAVE_PRI)
@@ -4746,7 +4748,8 @@ void dahdi_ec_enable(struct dahdi_pvt *p)
 			break;
 		}
 #endif	/* defined(HAVE_PRI) || defined(HAVE_SS7) */
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &p->echocancel);
+		pecp = &p->echocancel.head;
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 		if (res) {
 			ast_log(LOG_WARNING, "Unable to enable echo cancellation on channel %d (%s)\n", p->channel, strerror(errno));
 		} else {
@@ -4780,8 +4783,9 @@ void dahdi_ec_disable(struct dahdi_pvt *p)
 
 	if (p->echocanon) {
 		struct dahdi_echocanparams ecp = { .tap_length = 0 };
+		struct dahdi_echocanparams *pecp = &ecp;
 
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &ecp);
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 
 		if (res)
 			ast_log(LOG_WARNING, "Unable to disable echo cancellation on channel %d: %s\n", p->channel, strerror(errno));
@@ -18271,8 +18275,10 @@ static int process_dahdi(struct dahdi_chan_conf *confp
 				if ((varval = strchr(varname, '='))) {
 					*varval++ = '\0';
 					if ((tmpvar = ast_variable_new(varname, varval, ""))) {
-						tmpvar->next = confp->chan.vars;
-						confp->chan.vars = tmpvar;
+						if (ast_variable_list_replace(&confp->chan.vars, tmpvar)) {
+							tmpvar->next = confp->chan.vars;
+							confp->chan.vars = tmpvar;
+						}
 					}
 				}
 			}
