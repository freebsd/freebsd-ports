
$FreeBSD$

--- modules/registrar/reply.c.orig
+++ modules/registrar/reply.c
@@ -314,6 +314,7 @@
 	long code;
 	char* msg = MSG_200; /* makes gcc shut up */
 	char* buf;
+	int result;
 
 	if (contact.data_len > 0) {
 		add_lump_rpl( _m, contact.buf, contact.data_len, LUMP_RPL_HDR|LUMP_RPL_NODUP|LUMP_RPL_NOFREE);
@@ -347,7 +348,8 @@
 		}
 	}
 
-	if (sl_reply(_m, (char*)code, msg) == -1) {
+	result = (use_tm != 0) ? tmb.t_reply(_m, code, msg) : sl_reply(_m, (char*)code, msg);
+	if (result == -1) {
 		LOG(L_ERR, "send_reply(): Error while sending %ld %s\n", code, msg);
 		return -1;
 	} else return 0;	
