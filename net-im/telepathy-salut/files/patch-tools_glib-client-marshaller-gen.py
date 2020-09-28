--- tools/glib-client-marshaller-gen.py.orig	2011-08-16 11:04:41 UTC
+++ tools/glib-client-marshaller-gen.py
@@ -31,22 +31,22 @@ class Generator(object):
         for signal in signals:
             self.do_signal(signal)
 
-        print 'void'
-        print '%s_register_dbus_glib_marshallers (void)' % self.prefix
-        print '{'
+        print('void')
+        print('%s_register_dbus_glib_marshallers (void)' % self.prefix)
+        print('{')
 
-        all = self.marshallers.keys()
-        all.sort()
+        all = list(self.marshallers.keys())
+        sorted(all)
         for marshaller in all:
             rhs = self.marshallers[marshaller]
 
-            print '  dbus_g_object_register_marshaller (%s,' % marshaller
-            print '      G_TYPE_NONE,       /* return */'
+            print('  dbus_g_object_register_marshaller (%s,' % marshaller)
+            print('      G_TYPE_NONE,       /* return */')
             for type in rhs:
-                print '      G_TYPE_%s,' % type.replace('VOID', 'NONE')
-            print '      G_TYPE_INVALID);'
+                print('      G_TYPE_%s,' % type.replace('VOID', 'NONE'))
+            print('      G_TYPE_INVALID);')
 
-        print '}'
+        print('}')
 
 
 def types_to_gtypes(types):
