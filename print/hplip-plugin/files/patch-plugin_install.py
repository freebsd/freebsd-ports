--- ./plugin_install.py.orig	2014-04-04 10:53:11.000000000 +0000
+++ ./plugin_install.py	2014-04-14 21:21:12.685877696 +0000
@@ -144,30 +144,13 @@
 log.info("")
 
 PKIT = utils.to_bool(sys_conf.get('configure', 'policy-kit'))
-try:
-    from base.pkit import *
-    pkit_version = policykit_version()
-    if pkit_version:
-        if not user_pkit_version is None:
-            pkit_version = user_pkit_version
-        log.debug("pkit_version %d" % pkit_version)
-    try:
-        pkit = PolicyKit(pkit_version)
-        pkit_installed = True
-    except dbus.DBusException, ex:
-        pkit_installed = False
-except ImportError, e:
-    log.error("Unable to load pkit...is HPLIP installed?")
-    sys.exit(1)
+
 if not PKIT:
     pkit_installed = False
 log.debug("pkit_installed %s" % pkit_installed)
 
-if mode == INTERACTIVE_MODE:
+if True:
 
-    if not pkit_installed and not os.geteuid() == 0:
-        log.error("You must be root to install this plug-in.")
-        sys.exit(1)
 
     log.info(log.bold("You must agree to the license terms before installing the plug-in:"))
     log.info()
