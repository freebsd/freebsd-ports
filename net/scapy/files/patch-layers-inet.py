--- scapy/layers/inet.py.orig	2009-05-25 14:36:27.000000000 +0200
+++ scapy/layers/inet.py	2009-05-25 14:36:30.000000000 +0200
@@ -780,7 +780,7 @@
                 self.label.visible ^= 1
 
         visual.scene = visual.display()
-        visual.scene.exit_on_close(0)
+        #visual.scene.exit_on_close(0)
         start = visual.box()
         rings={}
         tr3d = {}
