--- monitor_wrap.c.orig	Fri Jun 21 02:43:43 2002
+++ monitor_wrap.c	Sun Jun 30 07:13:18 2002
@@ -664,6 +665,88 @@
 
 	buffer_free(&m);
 }
+
+void *
+mm_pam_init_ctx(Authctxt *authctxt)
+{
+	Buffer m;
+	int success;
+
+	debug3("%s", __func__);
+	buffer_init(&m);
+	buffer_put_cstring(&m, authctxt->user);
+	mm_request_send(pmonitor->m_recvfd, MONITOR_REQ_PAM_INIT_CTX, &m);
+	debug3("%s: waiting for MONITOR_ANS_PAM_INIT_CTX", __func__);
+	mm_request_receive_expect(pmonitor->m_recvfd, MONITOR_ANS_PAM_INIT_CTX, &m);
+	success = buffer_get_int(&m);
+	if (success == 0) {
+		debug3("%s: pam_init_ctx failed", __func__);
+		buffer_free(&m);
+		return (NULL);
+	}
+	buffer_free(&m);
+	return (authctxt);
+}
+
+int
+mm_pam_query(void *ctx, char **name, char **info,
+    u_int *num, char ***prompts, u_int **echo_on)
+{
+	Buffer m;
+	int i, ret;
+
+	debug3("%s", __func__);
+	buffer_init(&m);
+	mm_request_send(pmonitor->m_recvfd, MONITOR_REQ_PAM_QUERY, &m);
+	debug3("%s: waiting for MONITOR_ANS_PAM_QUERY", __func__);
+	mm_request_receive_expect(pmonitor->m_recvfd, MONITOR_ANS_PAM_QUERY, &m);
+	ret = buffer_get_int(&m);
+	debug3("%s: pam_query returned %d", __func__, ret);
+	*name = buffer_get_string(&m, NULL);
+	*info = buffer_get_string(&m, NULL);
+	*num = buffer_get_int(&m);
+	*prompts = xmalloc((*num + 1) * sizeof(char *));
+	*echo_on = xmalloc((*num + 1) * sizeof(u_int));
+	for (i = 0; i < *num; ++i) {
+		(*prompts)[i] = buffer_get_string(&m, NULL);
+		(*echo_on)[i] = buffer_get_int(&m);
+	}
+	buffer_free(&m);
+	return (ret);
+}
+
+int
+mm_pam_respond(void *ctx, u_int num, char **resp)
+{
+	Buffer m;
+	int i, ret;
+
+	debug3("%s", __func__);
+	buffer_init(&m);
+	buffer_put_int(&m, num);
+	for (i = 0; i < num; ++i)
+		buffer_put_cstring(&m, resp[i]);
+	mm_request_send(pmonitor->m_recvfd, MONITOR_REQ_PAM_RESPOND, &m);
+	debug3("%s: waiting for MONITOR_ANS_PAM_RESPOND", __func__);
+	mm_request_receive_expect(pmonitor->m_recvfd, MONITOR_ANS_PAM_RESPOND, &m);
+	ret = buffer_get_int(&m);
+	debug3("%s: pam_respond returned %d", __func__, ret);
+	buffer_free(&m);
+	return (ret);
+}
+
+void
+mm_pam_free_ctx(void *ctxtp)
+{
+	Buffer m;
+
+	debug3("%s", __func__);
+	buffer_init(&m);
+	mm_request_send(pmonitor->m_recvfd, MONITOR_REQ_PAM_FREE_CTX, &m);
+	debug3("%s: waiting for MONITOR_ANS_PAM_FREE_CTX", __func__);
+	mm_request_receive_expect(pmonitor->m_recvfd, MONITOR_ANS_PAM_FREE_CTX, &m);
+	buffer_free(&m);
+}
 #endif /* USE_PAM */
 
 /* Request process termination */
@@ -767,6 +850,7 @@
 	return ((authok == 0) ? -1 : 0);
 }
 
+#ifdef SKEY
 int
 mm_skey_query(void *ctx, char **name, char **infotxt,
    u_int *numprompts, char ***prompts, u_int **echo_on)
@@ -829,6 +913,7 @@
 
 	return ((authok == 0) ? -1 : 0);
 }
+#endif
 
 void
 mm_ssh1_session_id(u_char session_id[16])
