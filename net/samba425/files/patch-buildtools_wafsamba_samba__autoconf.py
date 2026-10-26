--- buildtools/wafsamba/samba_autoconf.py.orig	2026-10-26 11:27:51.019645000 +0700
+++ buildtools/wafsamba/samba_autoconf.py	2026-10-26 11:29:58.947632000 +0700
@@ -1043,6 +1043,10 @@
         # we don't want any libraries or modules to rely on runtime
         # resolution of symbols
         conf.env.undefined_ldflags = conf.ADD_LDFLAGS('-Wl,-no-undefined', testflags=True)
+
+        if (conf.env.undefined_ignore_ldflags == [] and
+            conf.CHECK_LDFLAGS(['-undefined', 'dynamic_lookup'] + conf.env.WERROR_CLFAGS)):
+            conf.env.undefined_ignore_ldflags = ['-undefined', 'dynamic_lookup']
 
         if (sys.platform == 'darwin' and
             conf.env.undefined_ignore_ldflags == [] and
