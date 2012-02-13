--- setup.py.orig	2012-02-10 14:58:50.000000000 +0800
+++ setup.py	2012-02-10 15:00:05.000000000 +0800
@@ -25,7 +25,8 @@
 		LIBS=['nsl', 'socket', 'dl']
 	elif sys.platform=="aix4":
 		LIBS=['nsl_r', 'dl']
-	elif sys.platform in ("freebsd4", "darwin", "mac", "linux2"):
+	elif sys.platform in ("freebsd4", "darwin", "mac", "linux2") \
+		or sys.platform.startswith("freebsd"):
 		LIBS=[]
 	else:
 		msg = "Don't know about system %s" % sys.platform
