diff --git ansible_collections/ansible/posix/plugins/modules/mount.py ansible_collections/ansible/posix/plugins/modules/mount.py
index b9e496e..6e2425b 100644
--- ansible_collections/ansible/posix/plugins/modules/mount.py
+++ ansible_collections/ansible/posix/plugins/modules/mount.py
@@ -279,7 +279,7 @@ def _set_mount_save_old(module, args):
     old_lines = []
     exists = False
     changed = False
-    escaped_args = dict([(k, _escape_fstab(v)) for k, v in iteritems(args) if k != 'warnings'])
+    escaped_args = dict([(k, _escape_fstab(v)) for k, v in iteritems(args)])
     new_line = '%(src)s %(name)s %(fstype)s %(opts)s %(dump)s %(passno)s\n'
 
     if platform.system() == 'SunOS':
@@ -804,7 +804,6 @@ def main():
             passno='-',
             fstab=module.params['fstab'],
             boot='yes' if module.params['boot'] else 'no',
-            warnings=[]
         )
         if args['fstab'] is None:
             args['fstab'] = '/etc/vfstab'
@@ -816,7 +815,6 @@ def main():
             passno='0',
             fstab=module.params['fstab'],
             boot='yes',
-            warnings=[]
         )
         if args['fstab'] is None:
             args['fstab'] = '/etc/fstab'
@@ -834,8 +832,7 @@ def main():
         linux_mounts = get_linux_mounts(module)
 
         if linux_mounts is None:
-            args['warnings'].append('Cannot open file /proc/self/mountinfo.'
-                                    ' Bind mounts might be misinterpreted.')
+            module.warn('Cannot open file /proc/self/mountinfo. Bind mounts might be misinterpreted.')
 
     # Override defaults with user specified params
     for key in ('src', 'fstype', 'passno', 'opts', 'dump', 'fstab'):
@@ -847,7 +844,7 @@ def main():
         # specified in 'opts',  mount module will ignore 'boot'.
         opts = args['opts'].split(',')
         if module.params['boot'] and 'noauto' in opts:
-            args['warnings'].append("Ignore the 'boot' due to 'opts' contains 'noauto'.")
+            module.warn("Ignore the 'boot' due to 'opts' contains 'noauto'.")
         elif not module.params['boot']:
             args['boot'] = 'no'
             opts.append('noauto')
