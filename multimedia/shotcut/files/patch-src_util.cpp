--- src/util.cpp.orig	2021-02-27 02:57:47 UTC
+++ src/util.cpp
@@ -480,6 +480,19 @@ bool Util::isMemoryLow()
         }
     }
     return false;
+#elif defined(__FreeBSD__)
+    QProcess p;
+    p.start("sysctl -n hw.usermem");
+    p.waitForFinished();
+    auto lines = p.readAllStandardOutput();
+    p.close();
+    bool ok = false;
+    auto availableKB = lines.toUInt(&ok);
+    if (ok) {
+	    return availableKB < kLowMemoryThresholdKB;
+    }
+
+    return false;
 #elif defined(Q_OS_LINUX)
     unsigned int availableKB = UINT_MAX;
     QFile meminfo("/proc/meminfo");
