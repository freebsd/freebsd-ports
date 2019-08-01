--- misc.c.orig	2019-08-01 13:54:47 UTC
+++ misc.c
@@ -62,7 +62,8 @@ void monitorhook(struct udata *userdata, time_t now, c
 	static UT_string *us = NULL;
 
 	utstring_renew(us);
-	utstring_printf(us, "%ld %s\n", now, topic);
+	utstring_printf(us, "%ld %s\n", (long)now, topic);
+
 
 	snprintf(mpath, sizeof(mpath), "%s/monitor", STORAGEDIR);
 	safewrite(mpath, UB(us));
