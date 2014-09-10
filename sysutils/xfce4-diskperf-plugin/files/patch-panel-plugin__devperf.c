--- panel-plugin/devperf.c.orig	2012-04-03 13:22:41 UTC
+++ panel-plugin/devperf.c
@@ -225,6 +225,93 @@
 
 	/**************************	Linux End	***************/
 
+#elif defined(__FreeBSD__)
+
+#include <sys/disk.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <sys/errno.h>
+#include <sys/resource.h>
+#include <sys/time.h>
+#include <devstat.h>
+#include <fcntl.h>
+#include <limits.h>
+#include <string.h>
+#include <syslog.h>
+#include <stdarg.h>
+
+#define MAXNAMELEN 256
+
+struct statinfo stats;
+struct devinfo dinfo;
+
+int DevPerfInit ()
+{
+	stats.dinfo = &dinfo;
+
+	return (0);
+}   
+
+int DevCheckStatAvailability(char const **strptr)
+{
+	return (0);
+}
+
+int DevGetPerfData (const void *p_pvDevice, struct devperf_t *perf)
+{
+	struct timeval tv;
+	struct timespec ts;
+	struct devstat dev;
+	kvm_t *kd = NULL;
+	int i, found = 0;
+	char *check_dev = (char *) p_pvDevice;
+
+	if(devstat_getdevs(kd, &stats) == -1) {
+		syslog(0, "DISKPERF: getdevs fail");
+	}
+
+	for(found = 0, i = 0; i < (stats.dinfo)->numdevs; i++) {
+		char dev_name[MAXNAMELEN];
+		dev = (stats.dinfo)->devices[i];
+		snprintf(dev_name, MAXNAMELEN-1, "%s%d",
+				dev.device_name, dev.unit_number);
+		if ((check_dev != NULL) && (strcmp(check_dev, dev_name) != 0))
+			continue;
+		else {
+			found = 1;
+			break;
+		}
+
+	}
+
+	if(check_dev != NULL && found) {
+		perf->wbytes = dev.bytes[DEVSTAT_WRITE];
+		perf->rbytes = dev.bytes[DEVSTAT_READ];
+		gettimeofday (&tv, 0);
+		perf->timestamp_ns = (uint64_t)1000ull * 1000ull * 1000ull *
+			tv.tv_sec + 1000ull * tv.tv_usec;
+		perf->qlen = dev.start_count - dev.end_count;
+		// I'm not sure about rbusy and wbusy calculation
+		bintime2timespec(&dev.busy_time, &ts);
+		perf->rbusy_ns = (uint64_t) ts.tv_nsec;
+		perf->wbusy_ns = perf->rbusy_ns;
+	}
+
+	return (0);
+}   
+
+#if 0				/* Standalone test purpose */
+int main ()
+{
+    struct devperf_t oPerf;
+    DevGetPerfData ((void*)"ada0", &oPerf);
+    printf ("%lu\t%lu\n", oPerf.rbytes, oPerf.wbytes);
+    return (0);
+}
+#endif
+
+
 
 #elif defined(__NetBSD__)
 	/**************************************************************/
