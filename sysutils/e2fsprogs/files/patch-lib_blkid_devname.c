--- lib/blkid/devname.c.orig	2020-03-21 04:24:04 UTC
+++ lib/blkid/devname.c
@@ -40,6 +40,9 @@
 #include <sys/sysmacros.h>
 #endif
 #include <time.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 
 #include "blkidP.h"
 
@@ -397,11 +400,15 @@ evms_probe_all(blkid_cache cache, int only_if_new)
 static int probe_all(blkid_cache cache, int only_if_new)
 {
 	FILE *proc;
+#ifndef __FreeBSD__
 	char line[1024];
+	int ma, mi;
+#else
+	char *line;
+#endif /* __FreeBSD__ */
 	char ptname0[129], ptname1[129], *ptname = 0;
 	char *ptnames[2];
 	dev_t devs[2];
-	int ma, mi;
 	unsigned long long sz;
 	int lens[2] = { 0, 0 };
 	int which = 0, last = 0;
@@ -423,20 +430,68 @@ static int probe_all(blkid_cache cache, int only_if_ne
 	lvm_probe_all(cache, only_if_new);
 #endif
 
+#ifndef __FreeBSD__
 	proc = fopen(PROC_PARTITIONS, "r");
 	if (!proc)
 		return -BLKID_ERR_PROC;
 
 	while (fgets(line, sizeof(line), proc)) {
+#else
+	size_t len, bufsiz = 4096;
+	char *buf = NULL;
+
+	for(;;) {
+		buf = realloc(buf, bufsiz);
+		if (!buf) return -BLKID_ERR_MEM;
+		len = bufsiz - 1;
+		if (sysctlbyname("kern.geom.conftxt", buf, &len, NULL, 0)) {
+			if (ENOMEM != errno) {
+				free(buf);
+				return -BLKID_ERR_IO;
+			}
+			bufsiz <<= 1;
+		} else {
+			if (len < bufsiz) buf[len] = '\0';
+			else              buf[bufsiz - 1] = '\0';
+			break;
+		}
+	}
+	char *str = buf;
+	while (line = strsep(&str, "\n")) {
+#endif /* __FreeBSD__ */
 		last = which;
 		which ^= 1;
 		ptname = ptnames[which];
 
+#ifndef __FreeBSD__
 		if (sscanf(line, " %d %d %llu %128[^\n ]",
 			   &ma, &mi, &sz, ptname) != 4)
 			continue;
 		devs[which] = makedev(ma, mi);
+#else
+		char type[5];
+		int dummy;
 
+		if (sscanf(line, "%*d %5s %128[^ ] %lld %d",
+			   type, ptname, &sz, &dummy) != 4)
+			continue;
+		sz /= 1024;
+
+		if (strcmp("PART", type) && strcmp("DISK", type))
+			continue;
+		{
+			struct stat st;
+			char dn[128];
+			if (snprintf(dn, sizeof dn, "/dev/%s", ptname) >= sizeof dn)
+				continue;
+
+			if (stat(dn, &st))
+				continue;
+
+			devs[which] = st.st_rdev;
+		}
+#endif /* __FreeBSD__ */
+
 		DBG(DEBUG_DEVNAME, printf("read partition name %s\n", ptname));
 
 		/* Skip whole disk devs unless they have no partitions.
@@ -507,7 +562,11 @@ static int probe_all(blkid_cache cache, int only_if_ne
 	if (lens[which])
 		probe_one(cache, ptname, devs[which], 0, only_if_new);
 
+#ifndef __FreeBSD__
 	fclose(proc);
+#else
+	free(buf);
+#endif /* __FreeBSD__ */
 	blkid_flush_cache(cache);
 	return 0;
 }
