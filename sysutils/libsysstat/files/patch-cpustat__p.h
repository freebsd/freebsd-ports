--- cpustat_p.h.orig	2021-04-07 06:58:34 UTC
+++ cpustat_p.h
@@ -27,6 +27,9 @@
 #ifndef LIBSYSSTAT__CPU_STAT__PRIVATE__INCLUDED
 #define LIBSYSSTAT__CPU_STAT__PRIVATE__INCLUDED
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 
 #include <QtCore/QObject>
 #include <QtCore/QtGlobal>
@@ -52,8 +55,15 @@ class CpuStatPrivate : public BaseStatPrivate (public)
     CpuStat::Monitoring monitoring() const;
     void setMonitoring(CpuStat::Monitoring value);
 
+#ifdef HAVE_SYSCTL_H
+    ulong minFreq(const QString &source) const;
+    ulong maxFreq(const QString &source) const;
+    ulong CurrentFreq(const QString);
+
+#else
     uint minFreq(const QString &source) const;
     uint maxFreq(const QString &source) const;
+#endif
 
 signals:
     void update(float user, float nice, float system, float other);
@@ -74,12 +84,21 @@ private slots: (private)
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
 
@@ -89,7 +108,14 @@ private slots: (private)
 
     CpuStat::Monitoring mMonitoring;
 
+#ifdef HAVE_SYSCTL_H
+    typedef QMap<QString, QPair<ulong, ulong> > Bounds;
+    int mib0[2];
+    int mib1[2];
+    int mib2[512][4];
+#else
     typedef QMap<QString, QPair<uint, uint> > Bounds;
+#endif
     Bounds mBounds;
 
     int mUserHz;
