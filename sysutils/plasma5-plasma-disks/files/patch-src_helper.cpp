The standard $PATH environment does not include the the location
where we expect smartmontools to be.

--- src/helper.cpp.orig	2020-09-04 15:52:07 UTC
+++ src/helper.cpp
@@ -30,7 +30,7 @@ ActionReply SMARTHelper::smartctl(const QVariantMap &a
     }
 
     // PATH is super minimal when invoked through dbus
-    setenv("PATH", "/usr/sbin:/sbin", 1);
+    setenv("PATH", "LOCALBASE/sbin:/usr/sbin:/sbin", 1);
     QProcess p;
     // json=c is badly documented and means "gimme json but don't pretty print"
     p.start(QStringLiteral("smartctl"),
