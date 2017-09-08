This patch fixes paths to rc scripts
The PREFIX fix won't be necessary anymore in further versions
See https://github.com/GoogleCloudPlatform/compute-image-packages/pull/440

--- google_compute_engine/instance_setup/instance_setup.py.orig	2017-07-18 16:43:14 UTC
+++ google_compute_engine/instance_setup/instance_setup.py
@@ -143,14 +143,14 @@ class InstanceSetup(object):
     """Initialize the SSH daemon."""
     # Exit as early as possible.
     # Instance setup systemd scripts block sshd from starting.
-    if os.path.exists('/bin/systemctl'):
+    if os.path.exists('%%PREFIX%%/bin/systemctl'):
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
 
