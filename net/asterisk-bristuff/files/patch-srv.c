
$FreeBSD$

--- srv.c.orig	Thu Aug 14 02:56:16 2003
+++ srv.c	Fri Oct 17 11:27:30 2003
@@ -246,13 +246,17 @@
 	int ret = -1;
 	struct __res_state srvstate;
 	char answer[MAX_SIZE];
+	static ast_mutex_t reslock = AST_MUTEX_INITIALIZER;
 
 	if (*port)
 		*port = 0;
-	res_ninit(&srvstate);	
-	if (chan && ast_autoservice_start(chan) < 0)
+	ast_mutex_lock(&reslock);
+	res_init();	
+	if (chan && ast_autoservice_start(chan) < 0) {
+		ast_mutex_unlock(&reslock);
 		return -1;
-	res = res_nsearch(&srvstate, service, C_IN, T_SRV, answer, sizeof(answer));
+	}
+	res = res_search(service, C_IN, T_SRV, answer, sizeof(answer));
 	if (res > 0) {
 		if ((res = parse_answer(host, hostlen, port, answer, res))) {
 			ast_log(LOG_WARNING, "Parse error returned %d\n", res);
@@ -267,6 +271,6 @@
 	}
 	if (chan)
 		ret |= ast_autoservice_stop(chan);
-	res_nclose(&srvstate);
+	ast_mutex_unlock(&reslock);
 	return ret;
 }
