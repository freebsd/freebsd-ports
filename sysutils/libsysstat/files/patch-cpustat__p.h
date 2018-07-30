--- cpustat_p.h.orig	2018-07-28 14:34:10 UTC
+++ cpustat_p.h
@@ -27,6 +27,9 @@
 #ifndef LIBSYSSTAT__CPU_STAT__PRIVATE__INCLUDED
 #define LIBSYSSTAT__CPU_STAT__PRIVATE__INCLUDED
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 
 #include <QtCore/QObject>
 #include <QtCore/QtGlobal>
@@ -52,8 +55,13 @@ public:
     CpuStat::Monitoring monitoring() const;
     void setMonitoring(CpuStat::Monitoring value);
 
+#ifdef HAVE_SYSCTL_H
+    ulong minFreq(const QString &source) const;
+    ulong maxFreq(const QString &source) const;
+#else
     uint minFreq(const QString &source) const;
     uint maxFreq(const QString &source) const;
+#endif
 
 signals:
     void update(float user, float nice, float system, float other);
@@ -74,12 +82,21 @@ private:
     {
         Values();
 
+#ifdef HAVE_SYSCTL_H
+        ulong user;
+        ulong nice;
+        ulong system;
+        ulong idle;
+        ulong other;
+        ulong total;
+#else
         qulonglong user;
         qulonglong nice;
         qulonglong system;
         qulonglong idle;
         qulonglong other;
         qulonglong total;
+#endif
 
         void sum();
 
@@ -89,7 +106,13 @@ private:
 
     CpuStat::Monitoring mMonitoring;
 
+#ifdef HAVE_SYSCTL_H
+    typedef QMap<QString, QPair<ulong, ulong> > Bounds;
+    int mib0[2];
+    int mib1[2];
+#else
     typedef QMap<QString, QPair<uint, uint> > Bounds;
+#endif
     Bounds mBounds;
 
     int mUserHz;
