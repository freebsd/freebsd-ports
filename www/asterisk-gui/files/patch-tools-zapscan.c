--- ./tools/zapscan.c.orig	Fri Nov  3 01:48:08 2006
+++ ./tools/zapscan.c	Sat Mar 31 17:54:39 2007
@@ -37,9 +37,9 @@
 	int oldsig=-1;
 	int fd = open("/dev/zap/ctl", O_RDWR);
 	struct zt_params ztp;
-	FILE *zdc = fopen("/etc/zaptel.conf", "a");
-	FILE *zsc = fopen("/etc/asterisk/zapscan.conf", "w");
-	FILE *zap = fopen("/etc/asterisk/zapata.conf", "a");
+	FILE *zdc = fopen("%%PREFIX%%/etc/zaptel.conf", "a");
+	FILE *zsc = fopen("%%PREFIX%%/etc/asterisk/zapscan.conf", "w");
+	FILE *zap = fopen("%%PREFIX%%/etc/asterisk/zapata.conf", "a");
 	if (fd < 0) {
 		fprintf(stderr, "Failed to open /dev/zap/ctl: %s\n", strerror(errno));
 		exit(1);
