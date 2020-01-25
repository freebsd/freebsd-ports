--- setup.py.orig	2019-10-09 09:44:36 UTC
+++ setup.py
@@ -16,17 +16,17 @@ if sys.version_info[:2] < (3, 6):
     )
 
 cmdclass = {}
-try:
-    from wheel.bdist_wheel import bdist_wheel
-except ImportError:
-    pass
-else:
+#try:
+#    from wheel.bdist_wheel import bdist_wheel
+#except ImportError:
+#    pass
+#else:
 
-    class UniversalBdistWheel(bdist_wheel):
-        def get_tag(self):
-            return ("py2.py3", "none") + bdist_wheel.get_tag(self)[2:]
+#    class UniversalBdistWheel(bdist_wheel):
+#        def get_tag(self):
+#            return ("py2.py3", "none") + bdist_wheel.get_tag(self)[2:]
 
-    cmdclass["bdist_wheel"] = UniversalBdistWheel
+#    cmdclass["bdist_wheel"] = UniversalBdistWheel
 
 
 class Download(Command):
@@ -212,9 +212,9 @@ class CustomEggInfo(egg_info):
         egg_info.run(self)
 
 
-cmdclass["download"] = Download
-cmdclass["build_ext"] = ExecutableBuildExt
-cmdclass["egg_info"] = CustomEggInfo
+#cmdclass["download"] = Download
+#cmdclass["build_ext"] = ExecutableBuildExt
+#cmdclass["egg_info"] = CustomEggInfo
 
 ots_sanitize = Executable(
     "ots.ots-sanitize", script="build.py", output_dir=os.path.join("build", "meson")
