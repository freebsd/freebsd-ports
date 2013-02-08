WARNING - this patch only fixes a compiler warning, but does not work on
FreeBSD (see src/usr.bin/w/w.c for how to do this), but it would work
with a /proc/uptime in Linux layout, discarding the decimal fraction.

--- ./procps/ps.c.orig	2012-12-22 23:39:01.000000000 +0100
+++ ./procps/ps.c	2013-01-22 00:04:53.000000000 +0100
@@ -83,7 +83,7 @@
 	if (open_read_close("/proc/uptime", buf, sizeof(buf)) <= 0)
 		bb_perror_msg_and_die("can't read %s", "/proc/uptime");
 	buf[sizeof(buf)-1] = '\0';
-	sscanf(buf, "%l", &uptime);
+	sscanf(buf, "%ld", &uptime);
 	return uptime;
 #else
 	struct timespec ts;
