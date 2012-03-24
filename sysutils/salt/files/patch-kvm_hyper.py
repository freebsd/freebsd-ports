--- salt-0.9.8/kvm_hyper.py     2012-03-22 10:57:13.019199302 -0600
+++ salt/modules/kvm_hyper.py        2012-03-22 10:57:45.441204588 -0600
@@ -46,6 +46,8 @@
         return False
     if __grains__['virtual'] != 'physical':
         return False
+    if __grains__['kernel'] != 'Linux':
+        return False
     if 'kvm_' not in open('/proc/modules').read():
         return False
     if not has_libvirt:
