--- SysInfo-0.23/SysInfo/__init__.py.orig	Mon Dec 29 11:45:41 2003
+++ SysInfo-0.23/SysInfo/__init__.py	Mon Dec 29 11:46:51 2003
@@ -129,7 +129,7 @@
         signal.set("key2[%(index)d]"   % vars(), _("Clock:"))
         signal.set("value2[%(index)d]" % vars(), self.__cpu_speed)
         signal.set("key3[%(index)d]"   % vars(), _("Cache:"))
-        signal.set("value3[%(index)d]" % vars(), self.__cpu_cache)
+        signal.set("value3[%(index)d]" % vars(), "Unknown")
         signal.set("fill[%(index)d]"   % vars(), load)
         signal.set("show1[%(index)d]"  % vars(), 1)
         signal.set("show2[%(index)d]"  % vars(), 1)
