--- res/res_pjsip_sdp_rtp.c.orig	2016-11-23 15:26:01 UTC
+++ res/res_pjsip_sdp_rtp.c
@@ -51,6 +51,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include "asterisk/acl.h"
 #include "asterisk/sdp_srtp.h"
 #include "asterisk/dsp.h"
+#include "asterisk/utils.h"
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
@@ -1493,7 +1494,11 @@ static int load_module(void)
 {
 	CHECK_PJSIP_SESSION_MODULE_LOADED();
 
-	ast_sockaddr_parse(&address_rtp, "::", 0);
+	if (ast_check_ipv6()) {
+		ast_sockaddr_parse(&address_rtp, "::", 0);
+	} else {
+		ast_sockaddr_parse(&address_rtp, "0.0.0.0", 0);
+	}
 
 	if (!(sched = ast_sched_context_create())) {
 		ast_log(LOG_ERROR, "Unable to create scheduler context.\n");
