-- Lowercase the platform name to match what pip wheel generates on FreeBSD.

--- site_scons/buildutils.py.orig
	2026-05-26 07:15:56 UTC
+++ site_scons/buildutils.py
@@ -1317,7 +1317,7 @@ def setup_python_env(env):
     py_version_short = parse_version(info["py_version_short"])
     py_version_full = parse_version(info["py_version"])
     py_version_nodot = info["py_version_nodot"]
-    plat = info['plat'].replace('-', '_').replace('.', '_')
+    plat = info['plat'].replace('-', '_').replace('.', '_').lower()
     numpy_include = info["numpy_include"]
     env.Prepend(CPPPATH=Dir('#include'))
     if env["system_sundials"] == "n":
