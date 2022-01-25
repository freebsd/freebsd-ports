--- setup.py.orig	2021-11-11 13:51:05 UTC
+++ setup.py
@@ -22,13 +22,13 @@ except ImportError:
 install_requires = [
     "Django>=3.0,<3.3",
     "django-modelcluster>=5.2,<6.0",
-    "django-taggit>=1.0,<2.0",
+    "django-taggit>=1.0",
     "django-treebeard>=4.2.0,<5.0,!=4.5",
     "djangorestframework>=3.11.1,<4.0",
     "django-filter>=2.2,<22",
-    "draftjs_exporter>=2.1.5,<3.0",
+    "draftjs_exporter>=2.1.5",
     "Pillow>=4.0.0,<10.0.0",
-    "beautifulsoup4>=4.8,<4.10",
+    "beautifulsoup4>=4.8,<4.11",
     "html5lib>=0.999,<2",
     "Willow>=1.4,<1.5",
     "requests>=2.11.1,<3.0",
