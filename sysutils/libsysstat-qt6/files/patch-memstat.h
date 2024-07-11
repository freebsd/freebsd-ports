--- memstat.h.orig	2019-01-30 19:24:29 UTC
+++ memstat.h
@@ -27,7 +27,9 @@
 #ifndef LIBSYSSTAT__MEM_STAT__INCLUDED
 #define LIBSYSSTAT__MEM_STAT__INCLUDED
 
-
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 #include <QtCore/QObject>
 
 #include "basestat.h"
@@ -36,7 +38,11 @@
 namespace SysStat {
 
 class MemStatPrivate;
-
+#if defined(HAVE_SYSCTL_H) && defined(HAVE_KVM_H)
+    int SwapDevices();
+    qulonglong MemGetByBytes(const QString property);
+    qulonglong MemGetByPages(const QString property);
+#endif
 class SYSSTATSHARED_EXPORT MemStat : public BaseStat
 {
     Q_OBJECT
