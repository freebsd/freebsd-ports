--- tools/manager-file.py.orig	2014-05-07 14:16:47 UTC
+++ tools/manager-file.py
@@ -87,18 +87,18 @@ gflags = {
 
 def write_manager(f, manager, protos):
     # pointless backwards compat section
-    print >> f, '[ConnectionManager]'
-    print >> f, 'BusName=org.freedesktop.Telepathy.ConnectionManager.' + manager
-    print >> f, 'ObjectPath=/org/freedesktop/Telepathy/ConnectionManager/' + manager
+    print('[ConnectionManager]', file=f)
+    print('BusName=org.freedesktop.Telepathy.ConnectionManager.' + manager, file=f)
+    print('ObjectPath=/org/freedesktop/Telepathy/ConnectionManager/' + manager, file=f)
 
     # protocols
-    for proto, params in protos.iteritems():
-        print >> f
-        print >> f, '[Protocol %s]' % proto
+    for proto, params in protos.items():
+        print(file=f)
+        print('[Protocol %s]' % proto, file=f)
 
         defaults = {}
 
-        for param, info in params.iteritems():
+        for param, info in params.items():
             dtype = info['dtype']
             flags = info.get('flags', '').split()
             struct_field = info.get('struct_field', param.replace('-', '_'))
@@ -115,15 +115,15 @@ def write_manager(f, manager, protos):
             else:
                 flags = ''
 
-            print >> f, 'param-%s=%s%s' % (param, desktop_string(dtype), flags)
+            print('param-%s=%s%s' % (param, desktop_string(dtype), flags), file=f)
 
-        for param, default in defaults.iteritems():
-            print >> f, 'default-%s=%s' % (param, default)
+        for param, default in defaults.items():
+            print('default-%s=%s' % (param, default), file=f)
 
 def write_c_params(f, manager, proto, struct, params):
-    print >> f, "static const TpCMParamSpec %s_%s_params[] = {" % (manager, proto)
+    print("static const TpCMParamSpec %s_%s_params[] = {" % (manager, proto), file=f)
 
-    for param, info in params.iteritems():
+    for param, info in params.items():
         dtype = info['dtype']
         flags = info.get('flags', '').split()
         struct_field = info.get('struct_field', param.replace('-', '_'))
@@ -146,7 +146,7 @@ def write_c_params(f, manager, proto, struct, params):
         else:
             struct_offset = 'G_STRUCT_OFFSET (%s, %s)' % (struct, struct_field)
 
-        print >> f, ('''  { %s, %s, %s,
+        print(('''  { %s, %s, %s,
     %s,
     %s, /* default */
     %s, /* struct offset */
@@ -154,14 +154,14 @@ def write_c_params(f, manager, proto, struct, params):
     %s, /* filter data */
     %s /* setter data */ },''' %
                 (c_string(param), c_string(dtype), gtypes[dtype], flags,
-                    default, struct_offset, filter, filter_data, setter_data))
+                    default, struct_offset, filter, filter_data, setter_data)), file=f)
 
-    print >> f, "  { NULL }"
-    print >> f, "};"
+    print("  { NULL }", file=f)
+    print("};", file=f)
 
 if __name__ == '__main__':
     environment = {}
-    execfile(sys.argv[1], environment)
+    exec(compile(open(sys.argv[1], "rb").read(), sys.argv[1], 'exec'), environment)
 
     filename = '%s/%s.manager' % (sys.argv[2], environment['MANAGER'])
     try:
