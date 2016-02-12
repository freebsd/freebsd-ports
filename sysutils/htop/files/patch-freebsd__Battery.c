--- freebsd/Battery.c.orig	2016-02-13 00:30:03.804015000 +0800
+++ freebsd/Battery.c	2016-02-13 00:31:05.662396000 +0800
@@ -6,10 +6,21 @@
 */
 
 #include "BatteryMeter.h"
+#include <sys/sysctl.h>
 
 void Battery_getData(double* level, ACPresence* isOnAC) {
-   // TODO
-   *level = -1;
-   *isOnAC = AC_ERROR;
+   int life;
+   size_t life_len = sizeof(life);
+   if (sysctlbyname("hw.acpi.battery.life", &life, &life_len, NULL, 0) == -1)
+      *level = -1;
+   else
+      *level = life;
+
+   int acline;
+   size_t acline_len = sizeof(acline);
+   if (sysctlbyname("hw.acpi.acline", &acline, &acline_len, NULL, 0) == -1)
+      *isOnAC = AC_ERROR;
+   else
+      *isOnAC = acline == 0 ? AC_ABSENT : AC_PRESENT;
 }
 
