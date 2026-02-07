--- tools/gobject-foo.py.orig	2014-05-07 14:28:02 UTC
+++ tools/gobject-foo.py
@@ -87,4 +87,4 @@ if __name__ == '__main__':
 
     head, tail = argv
 
-    print '\n'.join(gobject_header(head, tail, as_interface=as_interface))
+    print('\n'.join(gobject_header(head, tail, as_interface=as_interface)))
