--- src/client.c.orig	Thu May 12 14:01:28 2005
+++ src/client.c	Thu May 12 14:04:19 2005
@@ -841,6 +841,14 @@
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
