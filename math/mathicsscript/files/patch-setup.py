--- setup.py.orig	2021-07-05 14:18:53 UTC
+++ setup.py
@@ -47,14 +47,6 @@ exec(read("mathicsscript/version.py"))
 is_PyPy = platform.python_implementation() == "PyPy"
 
 EXTRAS_REQUIRE = {}
-for kind in ("dev", "full"):
-    extras_require = []
-    requirements_file = f"requirements-{kind}.txt"
-    for line in open(requirements_file).read().split("\n"):
-        if line and not line.startswith("#"):
-            requires = re.sub(r"([^#]+)(\s*#.*$)?", r"\1", line)
-            extras_require.append(requires)
-    EXTRAS_REQUIRE[kind] = extras_require
 
 setup(
     maintainer="Mathics Group",
