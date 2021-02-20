--- setup.py.orig	2021-02-15 16:30:03 UTC
+++ setup.py
@@ -64,36 +64,6 @@ packages = [
     "networkx.utils",
 ]
 
-docdirbase = "share/doc/networkx-%s" % version
-# add basic documentation
-data = [(docdirbase, glob("*.txt"))]
-# add examples
-for d in [
-    ".",
-    "advanced",
-    "algorithms",
-    "basic",
-    "3d_drawing",
-    "drawing",
-    "graph",
-    "javascript",
-    "jit",
-    "pygraphviz",
-    "subclass",
-]:
-    dd = os.path.join(docdirbase, "examples", d)
-    pp = os.path.join("examples", d)
-    data.append((dd, glob(os.path.join(pp, "*.txt"))))
-    data.append((dd, glob(os.path.join(pp, "*.py"))))
-    data.append((dd, glob(os.path.join(pp, "*.bz2"))))
-    data.append((dd, glob(os.path.join(pp, "*.gz"))))
-    data.append((dd, glob(os.path.join(pp, "*.mbox"))))
-    data.append((dd, glob(os.path.join(pp, "*.edgelist"))))
-# add js force examples
-dd = os.path.join(docdirbase, "examples", "javascript/force")
-pp = os.path.join("examples", "javascript/force")
-data.append((dd, glob(os.path.join(pp, "*"))))
-
 # add the tests
 package_data = {
     "networkx": ["tests/*.py"],
@@ -169,7 +139,6 @@ if __name__ == "__main__":
         project_urls=release.project_urls,
         classifiers=release.classifiers,
         packages=packages,
-        data_files=data,
         package_data=package_data,
         install_requires=install_requires,
         extras_require=extras_require,
