--- third_party/tensorpipe/tensorpipe/common/system.cc.orig	2025-06-04 18:15:56 UTC
+++ third_party/tensorpipe/tensorpipe/common/system.cc
@@ -102,6 +102,27 @@ std::string getPathForLinuxNamespace(LinuxNamespace ns
   return oss.str();
 }
 
+#elif defined(__FreeBSD__)
+
+#include <unistd.h>
+#include <stdio.h>
+#include <sys/sysctl.h>
+#include <time.h>
+
+optional<std::string> getBootIDInternal() {
+	char hostname[256];
+	(void)::gethostname(hostname, sizeof(hostname));
+
+	struct timeval boottime;
+	size_t size = sizeof(boottime);
+	(void)sysctlbyname("kern.boottime", &boottime, &size, nullptr, 0);
+
+	char buf[512];
+	::sprintf(buf, "%s-%ld-%ld", hostname, boottime.tv_sec, boottime.tv_usec);
+
+	return std::string(buf);
+}
+
 #endif
 
 } // namespace
