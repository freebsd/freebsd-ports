--- setup.py	2009-03-12 11:30:01.000000000 +0100
+++ setup.py.port	2009-03-16 22:25:32.000000000 +0100
@@ -8,6 +8,7 @@
 import glob
 from setuptools import setup, find_packages
 from setuptools.command import test
+from setuptools.command.install import install
 
 import sys
 import os
@@ -17,27 +18,27 @@
 keyw = """\
 """
 
-lib_data_files = glob.glob("library/*.py")
-lib_ui_data_files = glob.glob("library/ui/*.py")
-bp_data_files = glob.glob("builder/boilerplate/*")
-test_files = glob.glob("pyjs/tests/*")
-stub_files = glob.glob("stubs/*")
-lib_data_files += glob.glob("library/*.js")
-builtin_data_files = glob.glob("library/builtins/*.py")
-platform_data_files = glob.glob("library/platform/*.py")
-pyjamas_data_files = glob.glob("library/pyjamas/*.py")
-addons_data_files = glob.glob("addons/*.py")
-
-data_files = [("/usr/share/pyjamas/library", lib_data_files),
-              ("/usr/share/pyjamas/library/builtins", builtin_data_files),
-              ("/usr/share/pyjamas/library/ui", lib_ui_data_files),
-              ("/usr/share/pyjamas/builder/boilerplate", bp_data_files),
-              ("/usr/share/pyjamas/pyjs/tests", test_files),
-              ("/usr/share/pyjamas/stubs", stub_files),
-              ("/usr/share/pyjamas/library/platform", platform_data_files),
-              ("/usr/share/pyjamas/library/pyjamas", pyjamas_data_files),
-              ("/usr/share/pyjamas/addons", addons_data_files)
-              ]
+# yuk, spew, hurl.  but it works.  anyone got any better ideas?
+if sys.platform == "win32" or sys.platform.startswith("freebsd"):
+    datadir = os.path.join("share", "pyjamas")
+else:
+    # last thing we want on unix systems is the data files ending
+    # up in a random egg subdirectory, where no-one can find them.
+    # windows platform, i couldn't care less where they end up but
+    # it musn't be a fixed path, it must be a relative path.
+    datadir = "/usr/share/pyjamas"
+
+bp_data_files = glob.glob(os.path.join("builder", "boilerplate", "*"))
+test_files = glob.glob(os.path.join("pyjs", "tests", "*"))
+stub_files = glob.glob(os.path.join("stubs", "*"))
+addons_data_files = glob.glob(os.path.join("addons", "*.py"))
+
+data_files = [
+    (os.path.join(datadir, "builder", "boilerplate"), bp_data_files),
+    (os.path.join(datadir, "pyjs", "tests"), test_files),
+    (os.path.join(datadir, "stubs"), stub_files),
+    (os.path.join(datadir, "addons"), addons_data_files)
+]
 
 # main purpose of this function is to exclude "output" which
 # could have been built by a developer.
@@ -52,21 +53,28 @@
         if fname[-4:] == ".pyc": # ehmm.. noooo.
             continue 
         if os.path.isdir(p):
-            res += get_files(p)
+            get_dir(p)
         else:
             res.append(p)
     return res
 
-# ok - examples is a bit of a pain.  
-for d in glob.glob("examples/*"):
-    if os.path.isdir(d):
-        (pth, fname) = os.path.split(d)
-        expath = get_files(d)
-        pth = os.path.join("/usr/share/pyjamas/examples", fname)
-        #print pth, expath
-        data_files.append((pth, expath))
-    else:
-        data_files.append(("/usr/share/pyjamas/examples", [d]))
+def get_dir(dirname):
+    for d in glob.glob("%s/*" % dirname):
+        if os.path.isdir(d):
+            (pth, fname) = os.path.split(d)
+            expath = get_files(d)
+            pth = os.path.join(os.path.join(datadir, dirname), fname)
+            data_files.append((pth, expath))
+        else:
+            data_files.append((os.path.join(datadir, dirname), [d]))
+
+# recursively grab the library and the examples subdirectories - all contents
+get_dir("library")
+if not os.environ.has_key("NOPORTEXAMPLES"):
+    get_dir("examples")
+
+from pprint import pprint
+pprint(data_files)
 
 if __name__ == '__main__':
     setup(name = "Pyjamas",
@@ -77,7 +85,6 @@
         author = "The Pyjamas Project",
         author_email = "lkcl@lkcl.net",
         keywords = keyw,
-        #scripts = ["bin/pyjscompile", "bin/pyjsbuild"],
         entry_points = {'console_scripts':[
                        'pyjsbuild=pyjs.build:main',
                        'pyjscompile=pyjs:main',
