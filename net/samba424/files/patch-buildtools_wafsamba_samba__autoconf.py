--- buildtools/wafsamba/samba_autoconf.py.orig	2026-06-30 19:00:05 UTC
+++ buildtools/wafsamba/samba_autoconf.py
@@ -1040,5 +1040,5 @@ def SAMBA_CHECK_UNDEFINED_SYMBOL_FLAGS(conf):
         conf.env.undefined_ldflags = conf.ADD_LDFLAGS('-Wl,-no-undefined', testflags=True)
 
         if (conf.env.undefined_ignore_ldflags == [] and
-            conf.CHECK_LDFLAGS(['-undefined', 'dynamic_lookup'])):
+            conf.CHECK_LDFLAGS(['-undefined', 'dynamic_lookup'] + conf.env.WERROR_CFLAGS)):
             conf.env.undefined_ignore_ldflags = ['-undefined', 'dynamic_lookup']
