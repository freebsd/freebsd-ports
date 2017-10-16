--- sendmail/main.c.orig	2016-06-12 18:24:56.170900000 -0400
+++ sendmail/main.c	2016-06-12 18:30:07.426701000 -0400
@@ -4642,3 +4642,23 @@
 	sm_etype_printf,
 	"quick abort %0",
 };
+
+#ifdef USE_BLACKLIST
+static struct blacklist *blstate;
+
+void
+blacklist_init(void)
+{
+	blstate = blacklist_open();
+}
+
+void
+blacklist_notify(int a, int fd, char *msg)
+{
+	if (blstate == NULL)
+		blacklist_init();
+	if (blstate == NULL)
+		return;
+	(void)blacklist_r(blstate, a, fd, msg);
+}
+#endif
