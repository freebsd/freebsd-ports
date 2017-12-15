--- google_compute_engine/clock_skew/clock_skew_daemon.py.orig	2017-09-14 18:08:49 UTC
+++ google_compute_engine/clock_skew/clock_skew_daemon.py
@@ -59,9 +59,12 @@ class ClockSkewDaemon(object):
       response: string, the metadata response with the new drift token value.
     """
     self.logger.info('Clock drift token has changed: %s.', response)
-    command = ['/sbin/hwclock', '--hctosys']
+
+    ntpd_inactive = subprocess.call(['service', 'ntpd', 'status'])
     try:
-      subprocess.check_call(command)
+      if not ntpd_inactive: subprocess.check_call(['service', 'ntpd', 'stop'])
+      subprocess.check_call('ntpdate `awk \'$1=="server" {print $2}\' /etc/ntp.conf`', shell=True)
+      if not ntpd_inactive: subprocess.check_call(['service', 'ntpd', 'start'])
     except subprocess.CalledProcessError:
       self.logger.warning('Failed to sync system time with hardware clock.')
     else:
