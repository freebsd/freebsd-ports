--- setup.py.orig	2019-08-10 14:36:16 UTC
+++ setup.py
@@ -84,7 +84,7 @@ if link_args is None:
     elif os.environ.get('MINGW_PREFIX'):
         link_args = ['-lgss']
     else:
-        link_args = shlex.split(get_output('krb5-config --libs gssapi'))
+        link_args = shlex.split(get_output('%%KRB5CONFIG%% --libs gssapi'))
 
 if compile_args is None:
     if osx_has_gss_framework:
@@ -97,14 +97,14 @@ if compile_args is None:
     elif os.environ.get('MINGW_PREFIX'):
         compile_args = ['-fPIC']
     else:
-        compile_args = shlex.split(get_output('krb5-config --cflags gssapi'))
+        compile_args = shlex.split(get_output('%%KRB5CONFIG%% --cflags gssapi'))
 
 # add in the extra workarounds for different include structures
 if winkrb_path:
     prefix = winkrb_path
 else:
     try:
-        prefix = get_output('krb5-config gssapi --prefix')
+        prefix = get_output('%%KRB5CONFIG%% gssapi --prefix')
     except Exception:
         print("WARNING: couldn't find krb5-config; assuming prefix of %s"
               % str(sys.prefix))
