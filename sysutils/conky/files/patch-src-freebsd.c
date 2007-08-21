--- src/freebsd.c.orig	2007-08-05 08:48:13.000000000 +0400
+++ src/freebsd.c	2007-08-21 22:22:37.000000000 +0400
@@ -43,6 +43,14 @@
 #define	FREEBSD_DEBUG
 #endif
 
+#if __FreeBSD_version > 700050
+struct wi_req {
+	u_int16_t wi_len;
+	u_int16_t wi_type;
+	u_int16_t wi_val[WI_MAX_DATALEN];
+};
+#endif
+
 inline void proc_find_top(struct process **cpu, struct process **mem);
 
 u_int64_t diskio_prev = 0;
@@ -832,7 +840,7 @@
 	int fd;
 	struct apm_info info;
 
-	out = (char *)calloc(16, sizeof (char));
+	(char *)out = (char *)calloc(16, sizeof (char));
 
 	fd = open(APMDEV, O_RDONLY);
 	if (fd < 0) {
