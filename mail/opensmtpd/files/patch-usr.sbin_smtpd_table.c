--- usr.sbin/smtpd/table.c.orig	2026-01-09 22:12:00.007173000 +0000
+++ usr.sbin/smtpd/table.c	2026-01-09 22:15:18.366546000 +0000
@@ -158,6 +158,8 @@
 		log_warnx("warn: lookup key too long: %s", key);
 		errno = EINVAL;
 	}
+	else if (kind == K_AUTH)
+		r = table->t_backend->lookup(table, kind, key, NULL);
 	else
 		r = table->t_backend->lookup(table, kind, lkey, lk ? &buf : NULL);
 
