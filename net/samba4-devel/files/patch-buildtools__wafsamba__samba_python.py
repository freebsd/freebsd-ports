--- buildtools/wafsamba/samba_python.py.orig	2017-04-28 08:57:26 UTC
+++ buildtools/wafsamba/samba_python.py
@@ -76,17 +76,31 @@ def SAMBA_CHECK_PYTHON_HEADERS(conf, man
 
 def _check_python_headers(conf, mandatory):
     try:
+        from python import _get_python_variables
         Configure.ConfigurationError
         conf.check_python_headers(mandatory=mandatory)
+        conf.env['PYTHON_SO_ABI'] = _get_python_variables(
+            conf.env['PYTHON'],
+            ["get_config_var('SOABI') or ''"],
+            ['from distutils.sysconfig import get_config_var']
+        )[0]
     except Configure.ConfigurationError:
         if mandatory:
              raise
 
     if conf.env['PYTHON_VERSION'] > '3':
-        abi_pattern = os.path.splitext(conf.env['pyext_PATTERN'])[0]
-        conf.env['PYTHON_SO_ABI_FLAG'] = abi_pattern % ''
+        override_PYTHON3_SO_ABI_FLAG = os.getenv('PYTHON3_SO_ABI_FLAG', None)
+        if override_PYTHON3_SO_ABI_FLAG is not None:
+            conf.env['PYTHON_SO_ABI_FLAG'] = override_PYTHON3_SO_ABI_FLAG
+        if not conf.env['PYTHON_SO_ABI_FLAG']:
+            if conf.env['PYTHON_SO_ABI']:
+                conf.env['PYTHON_SO_ABI_FLAG'] = '.'+conf.env['PYTHON_SO_ABI']
+            else:
+                abi_pattern = os.path.splitext(conf.env['pyext_PATTERN'])[0]
+                conf.env['PYTHON_SO_ABI_FLAG'] = abi_pattern % ''
     else:
         conf.env['PYTHON_SO_ABI_FLAG'] = ''
+
     conf.env['PYTHON_LIBNAME_SO_ABI_FLAG'] = (
         conf.env['PYTHON_SO_ABI_FLAG'].replace('_', '-'))
 
