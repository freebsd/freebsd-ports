--- salt/modules/pkgng.py.orig	2017-10-09 16:37:42 UTC
+++ salt/modules/pkgng.py
@@ -1154,8 +1154,6 @@ def upgrade(*names, **kwargs):
         opts += 'n'
     if not dryrun:
         opts += 'y'
-    if opts:
-        opts = '-' + opts
 
     cmd = _pkg(jail, chroot, root)
     cmd.append('upgrade')
@@ -1181,7 +1179,11 @@ def upgrade(*names, **kwargs):
     return ret
 
 
-def clean(jail=None, chroot=None, root=None):
+def clean(jail=None,
+          chroot=None,
+          root=None,
+          clean_all=False,
+          dryrun=False):
     '''
     Cleans the local cache of fetched remote packages
 
@@ -1190,11 +1192,64 @@ def clean(jail=None, chroot=None, root=None):
     .. code-block:: bash
 
         salt '*' pkg.clean
-        salt '*' pkg.clean jail=<jail name or id>
-        salt '*' pkg.clean chroot=/path/to/chroot
+
+    jail
+        Cleans the package cache in the specified jail
+
+        CLI Example:
+
+        .. code-block:: bash
+
+            salt '*' pkg.clean jail=<jail name or id>
+
+    chroot
+        Cleans the package cache in the specified chroot (ignored if ``jail``
+        is specified)
+
+    root
+        Cleans the package cache in the specified root (ignored if ``jail``
+        is specified)
+
+        CLI Example:
+
+        .. code-block:: bash
+
+            salt '*' pkg.clean chroot=/path/to/chroot
+
+    clean_all
+        Clean all packages from the local cache (not just those that have been
+        superseded by newer versions).
+
+        CLI Example:
+
+        .. code-block:: bash
+
+        salt '*' pkg.clean clean_all=True
+
+    dryrun
+        Dry-run mode. This list of changes to the local cache is always
+        printed, but no changes are actually made.
+
+        CLI Example:
+
+        .. code-block:: bash
+
+            salt '*' pkg.clean dryrun=True
     '''
+    opts = ''
+    if clean_all:
+        opts += 'a'
+    if dryrun:
+        opts += 'n'
+    else:
+        opts += 'y'
+
+    cmd = _pkg(jail, chroot, root)
+    cmd.append('clean')
+    if opts:
+        cmd.append('-' + opts)
     return __salt__['cmd.run'](
-        _pkg(jail, chroot, root) + ['clean'],
+        cmd,
         output_loglevel='trace',
         python_shell=False
     )
