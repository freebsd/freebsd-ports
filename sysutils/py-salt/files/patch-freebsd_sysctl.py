--- salt/modules/freebsd_sysctl.py.orig	2016-10-31 11:21:36.000000000 -0600
+++ salt/modules/freebsd_sysctl.py      2016-11-02 08:44:19.743993000 -0600
@@ -56,17 +56,31 @@
     )
     cmd = 'sysctl -ae'
     ret = {}
-    out = __salt__['cmd.run'](cmd, output_loglevel='trace')
     comps = ['']
-    for line in out.splitlines():
-        if any([line.startswith('{0}.'.format(root)) for root in roots]):
-            comps = line.split('=', 1)
-            ret[comps[0]] = comps[1]
-        elif comps[0]:
-            ret[comps[0]] += '{0}\n'.format(line)
-        else:
-            continue
-    return ret
+
+    if config_file:
+        try:
+            with salt.utils.fopen(config_file, 'r') as f:
+                for line in f.readlines():
+                    l = line.strip()
+                    if l != "" and not l.startswith("#"):
+                        comps = line.split('=', 1)
+                        ret[comps[0]] = comps[1]
+            return ret
+        except (OSError, IOError):
+            log.error('Could not open sysctl config file')
+            return None
+    else:
+        out = __salt__['cmd.run'](cmd, output_loglevel='trace')
+        for line in out.splitlines():
+            if any([line.startswith('{0}.'.format(root)) for root in roots]):
+                comps = line.split('=', 1)
+                ret[comps[0]] = comps[1]
+            elif comps[0]:
+                ret[comps[0]] += '{0}\n'.format(line)
+            else:
+                 continue
+        return ret
 
 
 def get(name):
