--- setup.py.orig	2021-09-13 20:29:11 UTC
+++ setup.py
@@ -189,7 +189,6 @@ if compile_args is None:
     else:
         compile_args = shlex.split(run_command(f"{kc} --cflags krb5"))
 
-    compile_args.append("-Werror")
 
     # Python 3.8 on macOS errors on these deprecation warnings. We ignore them as things are fixed on 3.9 but the
     # code still needs to compile on 3.8.
