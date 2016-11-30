--- res/res_pjsip_t38.c.orig	2016-11-23 15:26:01 UTC
+++ res/res_pjsip_t38.c
@@ -44,6 +44,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include "asterisk/netsock2.h"
 #include "asterisk/channel.h"
 #include "asterisk/acl.h"
+#include "asterisk/utils.h"
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
@@ -918,7 +919,11 @@ static int load_module(void)
 {
 	CHECK_PJSIP_SESSION_MODULE_LOADED();
 
-	ast_sockaddr_parse(&address, "::", 0);
+	if (ast_check_ipv6()) {
+		ast_sockaddr_parse(&address, "::", 0);
+	} else {
+		ast_sockaddr_parse(&address, "0.0.0.0", 0);
+	}
 
 	if (ast_sip_session_register_supplement(&t38_supplement)) {
 		ast_log(LOG_ERROR, "Unable to register T.38 session supplement\n");
