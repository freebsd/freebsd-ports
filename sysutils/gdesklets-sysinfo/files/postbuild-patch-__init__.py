--- work/SysInfo/SysInfo/__init__.py.orig	Fri Sep 12 22:38:38 2003
+++ work/SysInfo/SysInfo/__init__.py	Mon Nov 17 10:50:07 2003
@@ -129,7 +129,8 @@
         signal.set("key2[%(index)d]"   % vars(), _("Clock:"))
         signal.set("value2[%(index)d]" % vars(), self.__cpu_speed)
         signal.set("key3[%(index)d]"   % vars(), _("Cache:"))
-        signal.set("value3[%(index)d]" % vars(), self.__cpu_cache)
+        #signal.set("value3[%(index)d]" % vars(), self.__cpu_cache)
+        signal.set("value3[%(index)d]" % vars(), _("unknown"))
         signal.set("fill[%(index)d]"   % vars(), load)
         signal.set("show1[%(index)d]"  % vars(), 1)
         signal.set("show2[%(index)d]"  % vars(), 1)
@@ -203,8 +204,8 @@
         l5 = lib.sys.get_load_avg_5m()
         l15 = lib.sys.get_load_avg_15m()
         tasks, running = lib.sys.get_tasks()
-        start = lib.sys.get_sysstart()
-        d_start, h_start, m_start, s_start = lib.convert.secs_to_dhms(start)
+        #start = lib.sys.get_sysstart()
+        #d_start, h_start, m_start, s_start = lib.convert.secs_to_dhms(start)
         uptime = lib.sys.get_uptime()
         d, h, m, s = lib.convert.secs_to_dhms(uptime)
         idletime = lib.sys.get_idletime()
@@ -216,9 +217,10 @@
         signal.set("key1[%(index)d]"      % vars(), _("Load:"))
         signal.set("value1[%(index)d]"    % vars(), str(l1) + " " + str(l5) + " " + str(l15))
         signal.set("key2[%(index)d]"      % vars(), _("Sysstart:"))
-        signal.set("value2[%(index)d]"    % vars(), str(h_start) + ":" +
-                                                    str(m_start) + ":" +
-                                                    str(s_start))
+        signal.set("value2[%(index)d]"    % vars(), _("unknown"))
+        #signal.set("value2[%(index)d]"    % vars(), str(h_start) + ":" +
+        #                                            str(m_start) + ":" +
+        #                                            str(s_start))
         signal.set("key3[%(index)d]"      % vars(), _("Uptime:"))
         signal.set("value3[%(index)d]"    % vars(), str(d) + "d " + \
                     str(h) + "h " + str(m) + "m ")
