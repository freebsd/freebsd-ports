--- build/lib/sysinfo.py.orig	Wed May 11 20:39:02 2005
+++ build/lib/sysinfo.py	Tue Jul 19 18:45:03 2005
@@ -170,6 +170,13 @@
     family_list = ['unix', 'freebsd', 'freebsd6', 'freebsd-6.0', 'freebsd-6.0-i586'] ))
 
 AddPlatform(Platform(
+    id = 'freebsd-7.0-i586',
+    platform = 'freebsd7',
+    arch = 'i386',
+    distribution_id = 'freebsd-7.0-i586',
+    family_list = ['unix', 'freebsd', 'freebsd7', 'freebsd-7.0', 'freebsd-7.0-i586'] ))
+
+AddPlatform(Platform(
     id = 'openbsd-3.3-i586',
     platform = 'openbsd33',
     arch = 'i386',
