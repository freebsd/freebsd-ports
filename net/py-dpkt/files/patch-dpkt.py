--- dpkt/bgp.py.orig	2006-10-01 08:41:30.000000000 +0200
+++ dpkt/bgp.py	2009-06-06 18:04:02.000000000 +0200
@@ -675,7 +675,7 @@
             self.failUnless(a.len == 12)
             self.failUnless(len(a.communities.list) == 3)
             c = a.communities.list[0]
-            self.failUnless(c.as == 65215)
+            self.failUnless(c._as == 65215)
             self.failUnless(c.value == 1)
             r = b2.update.announced[0]
             self.failUnless(r.len == 22)
@@ -712,7 +712,7 @@
             b4 = BGP(self.bgp4)
             self.failUnless(b4.len == 45)
             self.failUnless(b4.type == OPEN)
-            self.failUnless(b4.open.as == 237)
+            self.failUnless(b4.open._as == 237)
             self.failUnless(b4.open.param_len == 16)
             self.failUnless(len(b4.open.parameters) == 3)
             p = b4.open.parameters[0]
