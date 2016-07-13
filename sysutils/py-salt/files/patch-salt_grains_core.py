# Issue #33608
# https://github.com/saltstack/salt/issues/33608
--- salt/grains/core.py.orig	2016-05-25 22:30:31 UTC
+++ salt/grains/core.py
@@ -1422,6 +1422,7 @@ def os_data():
     else:
         grains['os'] = grains['kernel']
     if grains['kernel'] == 'FreeBSD':
+        grains.update(_bsd_cpudata(grains))
         try:
             grains['osrelease'] = __salt__['cmd.run']('freebsd-version -u').split('-')[0]
         except salt.exceptions.CommandExecutionError:
