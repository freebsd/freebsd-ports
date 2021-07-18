--- setup.py.orig	2021-06-06 16:11:07 UTC
+++ setup.py
@@ -47,10 +47,6 @@ exec(read("mathicsscript/version.py"))
 is_PyPy = platform.python_implementation() == "PyPy"
 
 dev_requires = []
-for line in open("requirements-dev.txt").read().split("\n"):
-    if line and not line.startswith("#"):
-        requires = re.sub(r"([^#]+)(\s*#.*$)?", r"\1", line)
-        dev_requires.append(requires)
 
 
 setup(
