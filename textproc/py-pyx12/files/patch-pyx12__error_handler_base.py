--- pyx12/error_handler_base.py.orig	2014-01-26 01:22:05 UTC
+++ pyx12/error_handler_base.py
@@ -145,12 +145,18 @@ class ErrorHandlerBase(object):
 
     @abc.abstractmethod
     def close_isa_loop(self, node, seg, src):
+        """
+        """
 
     @abc.abstractmethod
     def close_gs_loop(self, node, seg, src):
+        """
+        """
 
     @abc.abstractmethod
     def close_st_loop(self, node, seg, src):
+        """
+        """
 
     @abc.abstractmethod
     def find_node(self, type):
@@ -160,17 +166,23 @@ class ErrorHandlerBase(object):
 
     @abc.abstractmethod
     def _get_last_child(self):
-
-    @abc.abstractmethod
+        """
+        """
 
     @abc.abstractmethod
     def get_error_count(self):
+        """
+        """
 
     @abc.abstractmethod
     def get_first_child(self):
+        """
+        """
 
     @abc.abstractmethod
     def get_next_sibling(self):
+        """
+        """
 
     @abc.abstractmethod
     def __next__(self):
