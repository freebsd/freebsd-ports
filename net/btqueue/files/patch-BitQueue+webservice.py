--- BitQueue/webservice.py.old	Fri Jun  4 12:22:53 2004
+++ BitQueue/webservice.py	Fri Jun  4 04:34:25 2004
@@ -24,7 +24,10 @@
 
     def get_request(self):
         while not self._quit:
-            ifds,ofds,efds = select.select([self],[],[],10)
+            try:
+                ifds,ofds,efds = select.select([self],[],[],10)
+            except:
+                ifds,ofds,efds = [],[],[]
             if len(ifds) > 0:
                 return self.socket.accept()
         return None
