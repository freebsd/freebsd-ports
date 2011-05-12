--- tools/wafadmin/Tools/node_addon.py.orig	2011-05-11 14:41:33.000000000 +0800
+++ tools/wafadmin/Tools/node_addon.py	2011-05-11 14:41:49.000000000 +0800
@@ -29,6 +29,7 @@ def detect(conf):
 
   conf.env['LIBPATH_NODE'] = lib
   conf.env['CPPPATH_NODE'] = join(prefix, 'include', 'node')
+  conf.env.append_value('CPPPATH_NODE', join(prefix, 'include'))
 
   conf.env.append_value('CPPFLAGS_NODE', '-D_GNU_SOURCE')
   conf.env.append_value('CPPFLAGS_NODE', '-DEV_MULTIPLICITY=0')
