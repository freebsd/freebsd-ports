--- hotot/hotot.py.orig
+++ hotot/hotot.py
@@ -377,12 +377,10 @@
     config.loads();
     try:
         import ctypes
-        libc = ctypes.CDLL('libc.so.6')
-        libc.prctl(15, 'hotot', 0, 0, 0)
+        libc = ctypes.CDLL(os.path.join('/usr/lib', 'libc.so'))
+        libc.setproctitle('hotot')
     except:
-        import dl
-        libc = dl.open('/lib/libc.so.6')
-        libc.call('prctl', 15, 'hotot', 0, 0, 0)
+        pass
 
     agent.init_notify()
     app = Hotot()
