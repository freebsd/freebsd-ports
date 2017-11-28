--- google_compute_engine/instance_setup/instance_setup.py.orig	2017-09-14 18:08:49 UTC
+++ google_compute_engine/instance_setup/instance_setup.py
@@ -146,12 +146,12 @@ class InstanceSetup(object):
     # Instance setup systemd scripts block sshd from starting.
     if os.path.exists(constants.LOCALBASE + '/bin/systemctl'):
       return
-    elif (os.path.exists('/etc/init.d/ssh') or
-          os.path.exists('/etc/init/ssh.conf')):
+    elif (os.path.exists('/etc/rc.d/ssh') or
+          os.path.exists('/etc/rc/ssh.conf')):
       subprocess.call(['service', 'ssh', 'start'])
       subprocess.call(['service', 'ssh', 'reload'])
-    elif (os.path.exists('/etc/init.d/sshd') or
-          os.path.exists('/etc/init/sshd.conf')):
+    elif (os.path.exists('/etc/rc.d/sshd') or
+          os.path.exists('/etc/rc/sshd.conf')):
       subprocess.call(['service', 'sshd', 'start'])
       subprocess.call(['service', 'sshd', 'reload'])
 
