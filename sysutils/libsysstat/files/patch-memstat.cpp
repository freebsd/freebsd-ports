--- memstat.cpp.orig	2018-07-28 14:33:22 UTC
+++ memstat.cpp
@@ -26,10 +26,61 @@
 
 #include "memstat.h"
 #include "memstat_p.h"
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+#if defined(HAVE_KVM_H) && defined(HAVE_SYSCTL_H)
+extern "C"
+{
+    #include <paths.h>
+    #include <unistd.h>
+    #include <fcntl.h>
 
+    #include <kvm.h>
+    #include <sys/types.h>
+    #include <sys/sysctl.h>
+}
+#endif
 
 namespace SysStat {
+#ifdef HAVE_SYSCTL_H
+int SwapDevices()
+{
+    int buf;
+    size_t len = sizeof(int);
 
+    if (sysctlbyname("vm.nswapdev", &buf, &len, NULL, 0) < 0)
+        return 0;
+    else
+        return buf;
+}
+
+qulonglong MemGetByBytes(QString property)
+{
+    qulonglong buf=0;
+    size_t len = sizeof(qulonglong);
+
+    std::string s = property.toStdString();
+    const char *name = s.c_str();
+
+    if (sysctlbyname(name, &buf, &len, NULL, 0) < 0)
+        return 0;
+    else
+        return buf;
+}
+
+qulonglong MemGetByPages(QString name)
+{
+    qulonglong res = 0;
+
+
+    res = MemGetByBytes(name);
+    if (res > 0)
+        res = res * getpagesize();
+
+    return res;
+}
+#endif
 MemStatPrivate::MemStatPrivate(MemStat *parent)
     : BaseStatPrivate(parent)
 {
@@ -52,7 +103,38 @@ void MemStatPrivate::timeout()
     qulonglong memCached = 0;
     qulonglong swapTotal = 0;
     qulonglong swapFree = 0;
+#ifdef HAVE_SYSCTL_H
+    memTotal = MemGetByBytes("hw.physmem");
+    memFree = MemGetByPages("vm.stats.vm.v_free_count");
+    memBuffers = MemGetByBytes("vfs.bufspace");
+    memCached = MemGetByPages("vm.stats.vm.v_inactive_count");
+#endif
+#ifdef HAVE_KVM_H
+    qulonglong swapUsed = 0;
+    kvm_t *kd;
+    struct kvm_swap kswap[16]; /* size taken from pstat/pstat.c */
+
+    kd = kvm_open(NULL, _PATH_DEVNULL, NULL, O_RDONLY, "kvm_open");
+    if (kd == NULL)
+        kvm_close(kd);
+
+    if (kvm_getswapinfo(kd, kswap, (sizeof(kswap) / sizeof(kswap[0])), SWIF_DEV_PREFIX) > 0)
+    {
+        int swapd = SwapDevices();
+        /* TODO: loop over swap devives */
+        if (swapd >= 1)
+        {
+            swapTotal = static_cast<qulonglong>(kswap[0].ksw_total * getpagesize());
+            swapUsed = static_cast<qulonglong>(kswap[0].ksw_used * getpagesize());
+        }
+
+        kvm_close(kd);
+    }
+    else
+        kvm_close(kd);
+#endif
 
+#ifndef HAVE_SYSCTL_H
     const QStringList rows = readAllFile("/proc/meminfo").split(QChar('\n'), QString::SkipEmptyParts);
     for (const QString &row : rows)
     {
@@ -73,7 +155,7 @@ void MemStatPrivate::timeout()
         else if(tokens[0] == "SwapFree:")
             swapFree = tokens[1].toULong();
     }
-
+#endif
     if (mSource == "memory")
     {
         if (memTotal)
@@ -90,8 +172,11 @@ void MemStatPrivate::timeout()
     {
         if (swapTotal)
         {
+#ifndef HAVE_KVM_H
             float swapUsed_d = static_cast<float>(swapTotal - swapFree) / static_cast<float>(swapTotal);
-
+#else
+            float swapUsed_d = static_cast<float>(swapUsed) / static_cast<float>(swapTotal);
+#endif
             emit swapUpdate(swapUsed_d);
         }
     }
