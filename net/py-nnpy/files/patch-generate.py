--- generate.py.orig	2016-07-29 18:36:27 UTC
+++ generate.py
@@ -10,7 +10,7 @@ except ImportError:
 SITE_CFG = 'site.cfg'
 
 DEFAULT_INCLUDE_DIRS = ['/usr/include/nanomsg', '/usr/local/include/nanomsg']
-DEFAULT_HOST_LIBRARY = 'nanomsg'
+DEFAULT_HOST_LIBRARY = 'libnanomsg.so'
 
 BLOCKS = {'{': '}', '(': ')'}
 
