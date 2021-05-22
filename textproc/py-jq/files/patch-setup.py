--- setup.py.orig	2021-05-03 13:00:29 UTC
+++ setup.py
@@ -43,8 +43,6 @@ class jq_build_ext(build_ext):
     def run(self):
         if not os.path.exists(dependency_path(".")):
             os.makedirs(dependency_path("."))
-        self._build_oniguruma()
-        self._build_libjq()
         build_ext.run(self)
 
     def _build_oniguruma(self):
@@ -103,11 +101,7 @@ jq_extension = Extension(
     "jq",
     sources=["jq.c"],
     include_dirs=[os.path.join(jq_lib_dir, "src")],
-    extra_link_args=["-lm"],
-    extra_objects=[
-        os.path.join(jq_lib_dir, ".libs/libjq.a"),
-        os.path.join(oniguruma_lib_install_dir, "lib/libonig.a"),
-    ],
+    extra_link_args=["-lm", "-ljq", "-lonig"],
 )
 
 setup(
