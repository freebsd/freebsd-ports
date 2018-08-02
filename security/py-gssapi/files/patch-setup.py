--- setup.py.orig	2018-04-06 18:43:07 UTC
+++ setup.py
@@ -55,7 +55,7 @@ if link_args is None:
     elif os.environ.get('MINGW_PREFIX'):
         link_args = '-lgss'
     else:
-        link_args = get_output('krb5-config --libs gssapi')
+        link_args = get_output('%%KRB5CONFIG%% --libs gssapi')
 
 if compile_args is None:
     if osx_has_gss_framework:
@@ -63,14 +63,14 @@ if compile_args is None:
     elif os.environ.get('MINGW_PREFIX'):
         compile_args = '-fPIC'
     else:
-        compile_args = get_output('krb5-config --cflags gssapi')
+        compile_args = get_output('%%KRB5CONFIG%% --cflags gssapi')
 
 link_args = link_args.split()
 compile_args = compile_args.split()
 
 # add in the extra workarounds for different include structures
 try:
-    prefix = get_output('krb5-config gssapi --prefix')
+    prefix = get_output('%%KRB5CONFIG%% gssapi --prefix')
 except Exception:
     print("WARNING: couldn't find krb5-config; assuming prefix of %s"
           % str(sys.prefix))
