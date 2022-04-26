--- setup.py.orig	2022-03-24 18:36:13 UTC
+++ setup.py
@@ -91,17 +91,6 @@ if sys.version_info >= (2, 5):
     # distutils.setup() 'obsoletes' parameter not introduced until Python 2.5.
     extra_setup_params["obsoletes"] = ["suds"]
 
-if sys.version_info >= (3, 0):
-    extra_setup_params["use_2to3"] = True
-
-    #   Teach Python's urllib lib2to3 fixer that the old urllib2.__version__
-    # data member is now stored in the urllib.request module.
-    import lib2to3.fixes.fix_urllib
-    for x in lib2to3.fixes.fix_urllib.MAPPING["urllib2"]:
-        if x[0] == "urllib.request":
-            x[1].append("__version__")
-            break;
-
 #   Wrap long_description at 72 characters since PKG-INFO package distribution
 # metadata file stores this text with an 8 space indentation.
 long_description = """
@@ -167,7 +156,7 @@ setup(
     keywords=["SOAP", "web", "service", "client"],
     url=project_url,
     download_url=download_url,
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
 
     # 'maintainer' will be listed as the distribution package author.
     # Warning: Due to a 'distribute' package defect when used with Python 3
