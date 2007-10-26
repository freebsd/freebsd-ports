--- hpssd.py	Fri Oct 12 19:42:15 2007
+++ /usr/local/sbin/hpssd	Fri Oct 12 23:59:31 2007
@@ -664,6 +664,10 @@
     if prop.daemonize:
         utils.daemonize()
 
+    # Lock pidfile before we muck around with system state
+    # Patch by Henrique M. Holschuh <hmh@debian.org>
+    utils.get_pidfile_lock(os.path.join(sys_cfg.dirs.run, 'hpssd.pid'))
+
     # hpssd server dispatcher object
     try:
         server = hpssd_server(prop.hpssd_host, prop.hpssd_port)
@@ -688,6 +692,7 @@
 
         log.debug("Cleaning up...")
     finally:
+        os.remove(os.path.join(sys_cfg.dirs.run, 'hpssd.pid'))
         server.close()
         return 0
 
