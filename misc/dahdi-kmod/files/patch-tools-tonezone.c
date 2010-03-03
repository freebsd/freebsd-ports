--- tools/tonezone.c.orig	2008-08-06 06:43:02.000000000 +0700
+++ tools/tonezone.c	2010-03-03 17:24:01.000000000 +0600
@@ -46,6 +46,10 @@
 #define CLIP 32635
 #define BIAS 0x84
 
+#ifndef ENODATA
+#define ENODATA EINVAL
+#endif
+
 struct tone_zone *tone_zone_find(char *country)
 {
 	struct tone_zone *z;
@@ -440,7 +444,11 @@
 	dump_tone_zone(h, MAX_SIZE - space);
 #endif
 
+#if defined(__FreeBSD__)
+	if ((res = ioctl(fd, DAHDI_LOADZONE, &h))) {
+#else
 	if ((res = ioctl(fd, DAHDI_LOADZONE, h))) {
+#endif
 		fprintf(stderr, "ioctl(DAHDI_LOADZONE) failed: %s\n", strerror(errno));
 		return res;
 	}
