--- tools/glib-client-marshaller-gen.py.orig	2020-09-23 16:17:54 UTC
+++ tools/glib-client-marshaller-gen.py
@@ -31,23 +31,23 @@ class Generator(object):
         for signal in signals:
             self.do_signal(signal)
 
-        print 'void'
-        print '%s_register_dbus_glib_marshallers (void)' % self.prefix
-        print '{'
+        print('void')
+        print('%s_register_dbus_glib_marshallers (void)' % self.prefix)
+        print('{')
 
-        all = self.marshallers.keys()
+        all = list(self.marshallers.keys())
         all.sort()
         for marshaller in all:
             rhs = self.marshallers[marshaller]
 
-            print '  dbus_g_object_register_marshaller ('
-            print '      g_cclosure_marshal_generic,'
-            print '      G_TYPE_NONE,       /* return */'
+            print('  dbus_g_object_register_marshaller (')
+            print('      g_cclosure_marshal_generic,')
+            print('      G_TYPE_NONE,       /* return */')
             for type in rhs:
-                print '      G_TYPE_%s,' % type.replace('VOID', 'NONE')
-            print '      G_TYPE_INVALID);'
+                print('      G_TYPE_%s,' % type.replace('VOID', 'NONE'))
+            print('      G_TYPE_INVALID);')
 
-        print '}'
+        print('}')
 
 
 def types_to_gtypes(types):
