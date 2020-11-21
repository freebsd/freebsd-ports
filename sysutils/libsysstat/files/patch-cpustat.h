--- cpustat.h.orig	2020-11-03 14:45:02 UTC
+++ cpustat.h
@@ -27,14 +27,19 @@
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
+#endif
 class CpuStatPrivate;
 
 class SYSSTATSHARED_EXPORT CpuStat : public BaseStat
@@ -54,7 +59,6 @@ class SYSSTATSHARED_EXPORT CpuStat : public BaseStat (
 
     uint minFreq(const QString &source) const;
     uint maxFreq(const QString &source) const;
-
 signals:
     void update(float user, float nice, float system, float other, float frequencyRate, uint frequency);
     void update(float user, float nice, float system, float other);
