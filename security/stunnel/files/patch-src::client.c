Description: Do not pass null pointers to execvp().
Forwarded: https://stunnel.mirt.net/cgi-bin/bugzilla3/show_bug.cgi?id=2
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2009-11-13

--- src/client.c.orig
+++ src/client.c
@@ -859,6 +859,14 @@
         sigemptyset(&newmask);
         sigprocmask(SIG_SETMASK, &newmask, NULL);
 #endif
+	if (c->opt->execargs != NULL && c->opt->execargs[0] == NULL) {
+		free(c->opt->execargs);
+		c->opt->execargs = NULL;
+	}
+	if (c->opt->execargs == NULL) {
+		c->opt->execargs = calloc(2, sizeof(c->opt->execargs[0]));
+		c->opt->execargs[0] = c->opt->execname;
+	}
         execvp(c->opt->execname, c->opt->execargs);
         ioerror(c->opt->execname); /* execv failed */
         _exit(1);
