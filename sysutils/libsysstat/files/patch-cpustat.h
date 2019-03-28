--- cpustat.h.orig	2019-01-30 19:27:42 UTC
+++ cpustat.h
@@ -27,14 +27,20 @@
 #ifndef LIBSYSSTAT__CPU_STAT__INCLUDED
 #define LIBSYSSTAT__CPU_STAT__INCLUDED
 
-
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 #include <QtCore/QObject>
 
 #include "basestat.h"
 
 
 namespace SysStat {
-
+#ifdef HAVE_SYSCTL_H
+    char *GetFirstFragment(char *string, const char *delim);
+    int GetCpu(void);
+    ulong CurrentFreq(void);
+#endif
 class CpuStatPrivate;
 
 class SYSSTATSHARED_EXPORT CpuStat : public BaseStat
