--- setup.py.orig	2022-04-11 15:28:13 UTC
+++ setup.py
@@ -21,12 +21,12 @@ except ImportError:
 
 install_requires = [
     "Django>=3.2,<4.1",
-    "django-modelcluster>=5.2,<6.0",
+    "django-modelcluster>=5.2,<6.1",
     "django-taggit>=2.0,<3.0",
-    "django-treebeard>=4.5.1,<5.0",
+    "django-treebeard>=4.4.0,<5.0",
     "djangorestframework>=3.11.1,<4.0",
     "django-filter>=2.2,<22",
-    "draftjs_exporter>=2.1.5,<3.0",
+    "draftjs_exporter>=2.1.5",
     "Pillow>=4.0.0,<10.0.0",
     "beautifulsoup4>=4.8,<4.10",
     "html5lib>=0.999,<2",
