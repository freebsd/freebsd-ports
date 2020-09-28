--- tools/glib-signals-marshal-gen.py.orig	2011-08-16 11:04:41 UTC
+++ tools/glib-signals-marshal-gen.py
@@ -42,11 +42,11 @@ class Generator(object):
             self.do_signal(signal)
 
         all = self.marshallers.keys()
-        all.sort()
+        sorted(all)
         for marshaller in all:
             rhs = self.marshallers[marshaller]
             if not marshaller.startswith('g_cclosure'):
-                print 'VOID:' + ','.join(rhs)
+                print('VOID:' + ','.join(rhs))
 
 if __name__ == '__main__':
     argv = sys.argv[1:]
