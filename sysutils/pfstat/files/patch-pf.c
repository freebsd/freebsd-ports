--- pf.c.orig	2025-12-14 11:17:57 UTC
+++ pf.c
@@ -171,8 +171,8 @@ query_counters(int fd, void (*cb)(int, const char *, i
 	int i;
 
 	memset(&s, 0, sizeof(s));
-	if (ioctl(fd, DIOCGETSTATUS, &s)) {
-		fprintf(stderr, "ioctl: DIOCGETSTATUS: %s\n", strerror(errno));
+	if (ioctl(fd, DIOCGETSTATUSNV, &s)) {
+		fprintf(stderr, "ioctl: DIOCGETSTATUSNV: %s\n", strerror(errno));
 		return (1);
 	}
 	(*cb)(COL_TYPE_SINCE, "", 0, s.since);
