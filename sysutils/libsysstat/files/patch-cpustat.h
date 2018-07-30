--- cpustat.h.orig	2018-07-28 14:34:23 UTC
+++ cpustat.h
@@ -27,7 +27,9 @@
 #ifndef LIBSYSSTAT__CPU_STAT__INCLUDED
 #define LIBSYSSTAT__CPU_STAT__INCLUDED
 
-
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 #include <QtCore/QObject>
 
 #include "basestat.h"
@@ -35,6 +37,12 @@
 
 namespace SysStat {
 
+#ifdef HAVE_SYSCTL_H
+    char *GetFirstFragment(char *string, const char *delim);
+    int GetCpu(void);
+    ulong CurrentFreq(void);
+#endif
+
 class CpuStatPrivate;
 
 class SYSSTATSHARED_EXPORT CpuStat : public BaseStat
