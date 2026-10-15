--- cef/tools/make_config_header.py.orig	2026-09-06 17:31:54 UTC
+++ cef/tools/make_config_header.py
@@ -24,7 +24,7 @@ def make_config_header(gn_config):
 
   # All Linux builds use Ozone, and the X11 platform is enabled by default.
   # Check if the config is explicitly disabling it.
-  if sys.platform.startswith('linux') and \
+  if sys.platform.startswith(('linux', 'freebsd', 'openbsd')) and \
       not 'ozone_platform_x11=false' in lines:
     defines.append('#define CEF_X11 1')
 
