--- monitor.c.orig	Wed Jun 26 15:27:11 2002
+++ monitor.c	Mon Jul 15 21:33:45 2002
@@ -118,6 +118,10 @@
 
 #ifdef USE_PAM
 int mm_answer_pam_start(int, Buffer *);
+int mm_answer_pam_init_ctx(int, Buffer *);
+int mm_answer_pam_query(int, Buffer *);
+int mm_answer_pam_respond(int, Buffer *);
+int mm_answer_pam_free_ctx(int, Buffer *);
 #endif
 
 static Authctxt *authctxt;
@@ -156,6 +160,10 @@
     {MONITOR_REQ_AUTHPASSWORD, MON_AUTH, mm_answer_authpassword},
 #ifdef USE_PAM
     {MONITOR_REQ_PAM_START, MON_ONCE, mm_answer_pam_start},
+    {MONITOR_REQ_PAM_INIT_CTX, MON_ISAUTH, mm_answer_pam_init_ctx},
+    {MONITOR_REQ_PAM_QUERY, MON_ISAUTH, mm_answer_pam_query},
+    {MONITOR_REQ_PAM_RESPOND, MON_ISAUTH, mm_answer_pam_respond},
+    {MONITOR_REQ_PAM_FREE_CTX, MON_ONCE|MON_AUTHDECIDE, mm_answer_pam_free_ctx},
 #endif
 #ifdef BSD_AUTH
     {MONITOR_REQ_BSDAUTHQUERY, MON_ISAUTH, mm_answer_bsdauthquery},
@@ -198,6 +206,10 @@
 #endif
 #ifdef USE_PAM
     {MONITOR_REQ_PAM_START, MON_ONCE, mm_answer_pam_start},
+    {MONITOR_REQ_PAM_INIT_CTX, MON_ISAUTH, mm_answer_pam_init_ctx},
+    {MONITOR_REQ_PAM_QUERY, MON_ISAUTH, mm_answer_pam_query},
+    {MONITOR_REQ_PAM_RESPOND, MON_ISAUTH, mm_answer_pam_respond},
+    {MONITOR_REQ_PAM_FREE_CTX, MON_ONCE|MON_AUTHDECIDE, mm_answer_pam_free_ctx},
 #endif
     {0, 0, NULL}
 };
@@ -732,6 +744,101 @@
 	xfree(user);
 
 	return (0);
+}
+
+static void *pam_ctxt, *pam_authok;
+extern KbdintDevice pam_device;
+
+int
+mm_answer_pam_init_ctx(int socket, Buffer *m)
+{
+
+	debug3("%s", __func__);
+	authctxt->user = buffer_get_string(m, NULL);
+	pam_ctxt = (pam_device.init_ctx)(authctxt);
+	pam_authok = NULL;
+	buffer_clear(m);
+	if (pam_ctxt != NULL) {
+		monitor_permit(mon_dispatch, MONITOR_REQ_PAM_FREE_CTX, 1);
+		buffer_put_int(m, 1);
+	} else {
+		buffer_put_int(m, 0);
+	}
+	mm_request_send(socket, MONITOR_ANS_PAM_INIT_CTX, m);
+	return (0);
+}
+
+int
+mm_answer_pam_query(int socket, Buffer *m)
+{
+	char *name, *info, **prompts;
+	u_int num, *echo_on;
+	int i, ret;
+
+	debug3("%s", __func__);
+	pam_authok = NULL;
+	ret = (pam_device.query)(pam_ctxt, &name, &info, &num, &prompts, &echo_on);
+	if (num > 1 || name == NULL || info == NULL)
+		ret = -1;
+	buffer_clear(m);
+	buffer_put_int(m, ret);
+	buffer_put_cstring(m, name);
+	xfree(name);
+	buffer_put_cstring(m, info);
+	xfree(info);
+	buffer_put_int(m, num);
+	for (i = 0; i < num; ++i) {
+		buffer_put_cstring(m, prompts[i]);
+		xfree(prompts[i]);
+		buffer_put_int(m, echo_on[i]);
+	}
+	if (prompts != NULL)
+		xfree(prompts);
+	if (echo_on != NULL)
+		xfree(echo_on);
+	mm_request_send(socket, MONITOR_ANS_PAM_QUERY, m);
+	return (0);
+}
+
+int
+mm_answer_pam_respond(int socket, Buffer *m)
+{
+	char **resp;
+	u_int num;
+	int i, ret;
+
+	debug3("%s", __func__);
+	pam_authok = NULL;
+	num = buffer_get_int(m);
+	if (num > 0) {
+		resp = xmalloc(num * sizeof(char *));
+		for (i = 0; i < num; ++i)
+			resp[i] = buffer_get_string(m, NULL);
+		ret = (pam_device.respond)(pam_ctxt, num, resp);
+		for (i = 0; i < num; ++i)
+			xfree(resp[i]);
+		xfree(resp);
+	} else {
+		ret = (pam_device.respond)(pam_ctxt, num, NULL);
+	}
+	buffer_clear(m);
+	buffer_put_int(m, ret);
+	mm_request_send(socket, MONITOR_ANS_PAM_RESPOND, m);
+	auth_method = "keyboard-interactive/pam";
+	if (ret == 0)
+		pam_authok = pam_ctxt;
+	return (0);
+}
+
+int
+mm_answer_pam_free_ctx(int socket, Buffer *m)
+{
+
+	debug3("%s", __func__);
+	(pam_device.free_ctx)(pam_ctxt);
+	buffer_clear(m);
+	mm_request_send(socket, MONITOR_ANS_PAM_FREE_CTX, m);
+	return (pam_authok == pam_ctxt);
 }
 #endif
 
