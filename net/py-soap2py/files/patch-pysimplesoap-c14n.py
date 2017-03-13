--- pysimplesoap/c14n.py.orig	2014-09-17 01:42:27 UTC
+++ pysimplesoap/c14n.py
@@ -174,7 +174,7 @@ class _implementation:
         elif node.nodeType == Node.DOCUMENT_TYPE_NODE:
             pass
         else:
-            raise TypeError, str(node)
+            raise TypeError(str(node))
 
 
     def _inherit_context(self, node):
@@ -217,7 +217,7 @@ class _implementation:
             elif child.nodeType == Node.DOCUMENT_TYPE_NODE:
                 pass
             else:
-                raise TypeError, str(child)
+                raise TypeError(str(child))
     handlers[Node.DOCUMENT_NODE] = _do_document
 
 
@@ -346,9 +346,9 @@ class _implementation:
                     
                 if not ns_rendered.has_key(prefix) and not ns_local.has_key(prefix):
                     if not ns_unused_inherited.has_key(prefix):
-                        raise RuntimeError,\
+                        raise RuntimeError(\
                             'For exclusive c14n, unable to map prefix "%s" in %s' %(
-                            prefix, node)
+                            prefix, node))
                     
                     ns_local[prefix] = ns_unused_inherited[prefix]
                     del ns_unused_inherited[prefix]
