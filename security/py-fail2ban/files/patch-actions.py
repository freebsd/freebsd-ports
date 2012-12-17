--- server/actions.py.orig	2012-11-27 18:16:18.000000000 +0100
+++ server/actions.py	2012-11-27 18:17:04.000000000 +0100
@@ -206 +206 @@
-		logSys.warn("[%s] Unban %s" % (self.jail.getName(), aInfo["ip"]))
+		logSys.warn("[%s] Unban %s" % (self.jail.getName(), str(aInfo["ip"])))
