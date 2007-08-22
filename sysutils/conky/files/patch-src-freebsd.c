--- src/freebsd.c.orig	Sun Aug  5 08:48:13 2007
+++ src/freebsd.c	Wed Aug 22 10:22:24 2007
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
@@ -831,6 +839,7 @@
 {
 	int fd;
 	struct apm_info info;
+	char *out;
 
 	out = (char *)calloc(16, sizeof (char));
 
