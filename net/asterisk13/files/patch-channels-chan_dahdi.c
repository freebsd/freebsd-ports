--- channels/chan_dahdi.c.orig	2017-10-13 17:46:56 UTC
+++ channels/chan_dahdi.c
@@ -61,10 +61,10 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revision$")
 #include <signal.h>
 #else
 #include <sys/signal.h>
+#include <sys/sysmacros.h>
 #endif
 #include <sys/stat.h>
 #include <math.h>
-#include <sys/sysmacros.h>
 
 #include "sig_analog.h"
 /* Analog signaling is currently still present in chan_dahdi for use with
@@ -4666,6 +4666,8 @@ void dahdi_ec_enable(struct dahdi_pvt *p)
 		return;
 	}
 	if (p->echocancel.head.tap_length) {
+		struct dahdi_echocanparams *pecp;
+
 #if defined(HAVE_PRI) || defined(HAVE_SS7)
 		switch (p->sig) {
 #if defined(HAVE_PRI)
@@ -4696,7 +4698,9 @@ void dahdi_ec_enable(struct dahdi_pvt *p)
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
@@ -4730,8 +4734,9 @@ void dahdi_ec_disable(struct dahdi_pvt *p)
 
 	if (p->echocanon) {
 		struct dahdi_echocanparams ecp = { .tap_length = 0 };
+		struct dahdi_echocanparams *pecp = &ecp;
 
-		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &ecp);
+		res = ioctl(p->subs[SUB_REAL].dfd, DAHDI_ECHOCANCEL_PARAMS, &pecp);
 
 		if (res)
 			ast_log(LOG_WARNING, "Unable to disable echo cancellation on channel %d: %s\n", p->channel, strerror(errno));
