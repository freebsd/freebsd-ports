Fix build on FreeBSD 12.x.

/usr/include/sys/sysctl.h:1117:25: error: unknown type name 'u_int'; did you mean 'uint'?
int     sysctl(const int *, u_int, void *, size_t *, const void *, size_t);
                            ^
--- daemon/backends/upower/freebsdbacklighthelper.cpp.orig	2023-12-11 05:59:31 UTC
+++ daemon/backends/upower/freebsdbacklighthelper.cpp
@@ -31,8 +31,8 @@
 
 #include <algorithm>
 #include <climits>
-#include <sys/sysctl.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #include <sys/utsname.h>
 
 #define BACKLIGHT_PATH "/dev/backlight/"
