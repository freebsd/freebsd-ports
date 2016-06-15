--- salt/modules/pkgng.py.orig	2016-05-25 22:30:31 UTC
+++ salt/modules/pkgng.py
@@ -97,7 +97,8 @@ def _get_pkgng_version(jail=None, chroot
     '''
     return the version of 'pkg'
     '''
-    return __salt__['cmd.run']([_pkg(jail, chroot), '--version']).strip()
+    cmd = _pkg(jail, chroot) + ['--version']
+    return __salt__['cmd.run'](cmd).strip()
 
 
 def _get_version(name, results):
@@ -287,9 +288,9 @@ def latest_version(*names, **kwargs):
     for name in names:
         # FreeBSD supports packages in format java/openjdk7
         if '/' in name:
-            cmd = [_pkg(jail, chroot), 'search']
+            cmd = _pkg(jail, chroot) + ['search']
         else:
-            cmd = [_pkg(jail, chroot), 'search', '-S', 'name', '-Q', 'version', '-e']
+            cmd = _pkg(jail, chroot) + ['search', '-S', 'name', '-Q', 'version', '-e']
         if quiet:
             cmd.append('-q')
         cmd.append(name)
