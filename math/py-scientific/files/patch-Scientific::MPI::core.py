--- Scientific/MPI/core.py.orig	Sun Dec  5 11:42:48 2004
+++ Scientific/MPI/core.py	Sun Dec  5 11:43:28 2004
@@ -315,7 +315,7 @@
                         return data, 0, data_tag, len(data)
                 raise MPIError, "no message received"
 
-            def receiveString(self, None, source=None, tag=None):
+            def receiveString(self, _None, source=None, tag=None):
                 array, source, tag, length = self.receive(source, tag)
                 return array.tostring(), source, tag
 
