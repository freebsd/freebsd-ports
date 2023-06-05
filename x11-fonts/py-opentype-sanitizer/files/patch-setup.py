--- setup.py.orig	2023-05-31 23:17:56 UTC
+++ setup.py
@@ -17,19 +17,8 @@ if sys.version_info[:2] < (3, 6):
     )
 
 cmdclass = {}
-try:
-    from wheel.bdist_wheel import bdist_wheel
-except ImportError:
-    pass
-else:
 
-    class UniversalBdistWheel(bdist_wheel):
-        def get_tag(self):
-            return ("py2.py3", "none") + bdist_wheel.get_tag(self)[2:]
 
-    cmdclass["bdist_wheel"] = UniversalBdistWheel
-
-
 class Download(Command):
 
     user_options = [
@@ -213,10 +202,6 @@ class CustomEggInfo(egg_info):
         egg_info.run(self)
 
 
-cmdclass["download"] = Download
-cmdclass["build_ext"] = ExecutableBuildExt
-cmdclass["egg_info"] = CustomEggInfo
-
 build_options = []
 platform_tags = get_platform().split("-")
 if "macosx" in platform_tags:
@@ -227,7 +212,7 @@ if "macosx" in platform_tags:
 
 ots_sanitize = Executable(
     "ots.ots-sanitize",
-    script="build.py",
+    script="build_ext.py",
     options=build_options,
     output_dir=os.path.join("build", "meson"),
 )
