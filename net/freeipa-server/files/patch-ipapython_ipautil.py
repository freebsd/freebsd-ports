--- ipapython/ipautil.py.orig	2026-07-16 09:44:00 UTC
+++ ipapython/ipautil.py
@@ -489,7 +489,7 @@ def run(args, stdin=None, raiseonerr=True, nolog=(), e
     if env is None:
         # copy default env
         env = copy.deepcopy(os.environ)
-        env["PATH"] = "/bin:/sbin:/usr/kerberos/bin:/usr/kerberos/sbin:/usr/bin:/usr/sbin"
+        env["PATH"] = "/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin"
     if stdin:
         p_in = subprocess.PIPE
     if skip_output:
@@ -1368,7 +1368,9 @@ def wait_for_open_socket(socket_name, timeout=0):
             s.close()
             break
         except socket.error as e:
-            if e.errno in (2,111):  # 111: Connection refused, 2: File not found
+            # ECONNREFUSED is 111 on Linux but 61 on FreeBSD, so compare
+            # against the symbolic values instead of hardcoded numbers.
+            if e.errno in (errno.ENOENT, errno.ECONNREFUSED):
                 if timeout and time.time() > op_timeout: # timeout exceeded
                     raise e
                 time.sleep(1)
