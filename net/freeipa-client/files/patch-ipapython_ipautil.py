--- ipapython/ipautil.py.orig	2026-01-16 09:23:32 UTC
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
