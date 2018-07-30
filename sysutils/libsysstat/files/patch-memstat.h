--- memstat.h.orig	2018-07-28 14:33:10 UTC
+++ memstat.h
@@ -27,6 +27,9 @@
 #ifndef LIBSYSSTAT__MEM_STAT__INCLUDED
 #define LIBSYSSTAT__MEM_STAT__INCLUDED
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 
 #include <QtCore/QObject>
 
@@ -35,6 +38,12 @@
 
 namespace SysStat {
 
+#if defined(HAVE_SYSCTL_H) && defined(HAVE_KVM_H)
+    int SwapDevices();
+    qulonglong MemGetByBytes(const QString property);
+    qulonglong MemGetByPages(const QString property);
+#endif
+
 class MemStatPrivate;
 
 class SYSSTATSHARED_EXPORT MemStat : public BaseStat
