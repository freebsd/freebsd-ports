--- setup.py.orig	2022-08-08 21:14:44 UTC
+++ setup.py
@@ -174,8 +174,6 @@ if not SKIP_EXTENSIONS:
         else:
             compile_args = shlex.split(run_command(f"{kc} --cflags krb5"))
 
-        compile_args.append("-Werror")
-
         # Python 3.8 on macOS errors on these deprecation warnings. We ignore them as things are fixed on 3.9 but the
         # code still needs to compile on 3.8.
         if sys.platform == "darwin" and sys.version_info[:2] == (3, 8):
