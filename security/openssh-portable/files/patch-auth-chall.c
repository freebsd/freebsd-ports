--- auth-chall.c	Tue Jun  5 20:56:17 2001
+++ cvs-current/auth-chall.c	Wed Sep 24 20:24:27 2003
@@ -76,7 +77,33 @@
 		return 0;
 	resp[0] = (char *)response;
 	res = device->respond(authctxt->kbdintctxt, 1, resp);
+	if (res == 1) {
+		/* postponed - send a null query just in case */
+		char *name, *info, **prompts;
+		u_int i, numprompts, *echo_on;
+
+		res = device->query(authctxt->kbdintctxt, &name, &info,
+		    &numprompts, &prompts, &echo_on);
+		if (res == 0) {
+			for (i = 0; i < numprompts; i++)
+				xfree(prompts[i]);
+			xfree(prompts);
+			xfree(name);
+			xfree(echo_on);
+			xfree(info);
+		}
+		/* if we received more prompts, we're screwed */
+		res = (res == 0 && numprompts == 0) ? 0 : -1;
+	}
 	device->free_ctx(authctxt->kbdintctxt);
 	authctxt->kbdintctxt = NULL;
 	return res ? 0 : 1;
+}
+void
+abandon_challenge_response(Authctxt *authctxt)
+{
+	if (authctxt->kbdintctxt != NULL) {
+		device->free_ctx(authctxt->kbdintctxt);
+		authctxt->kbdintctxt = NULL;
+	}
 }
