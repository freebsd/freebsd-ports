--- SysInfo/SysInfo.py.orig	Fri Jun 11 11:43:36 2004
+++ SysInfo/SysInfo.py	Fri Jun 11 11:46:47 2004
@@ -72,7 +72,7 @@
 
         cpu_type    = lib.cpu.get_model()
         cpu_speed   = lib.cpu.get_speed()
-        cpu_cache   = lib.cpu.get_cache_size()
+        cpu_cache   = "n/a" #lib.cpu.get_cache_size()
         total, load = lib.cpu.get_load()
 
         signal.set("value1[%(index)d]"    % vars(), cpu_type)
