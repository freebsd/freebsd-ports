--- setup.py.orig	2016-05-02 16:57:01 UTC
+++ setup.py
@@ -35,36 +35,36 @@ __platform__ = platform.system()
 is_windows = __platform__ in ['Windows']
 
 requirements = [
-    "waitress==0.8.8",
-    "webob>=1.0.8,<=1.1.1",
-    "webtest==1.4.3",
-    "Pylons>=1.0.0,<=1.0.2",
-    "Beaker==1.6.4",
-    "WebHelpers==1.3",
-    "formencode>=1.2.4,<=1.2.6",
-    "SQLAlchemy==0.7.10",
-    "Mako>=0.9.0,<=1.0.0",
+    "waitress>=0.8.8",
+    "webob>=1.0.8",
+    "webtest>=1.4.3",
+    "Pylons>=1.0.0",
+    "Beaker>=1.6.4",
+    "WebHelpers>=1.3",
+    "formencode>=1.2.4",
+    "SQLAlchemy>=0.7.10",
+    "Mako>=0.9.0",
     "pygments>=1.5",
-    "whoosh>=2.4.0,<=2.5.7",
-    "celery>=2.2.5,<2.3",
-    "babel>=0.9.6,<=1.3",
-    "python-dateutil>=1.5.0,<2.0.0",
-    "markdown==2.2.1",
-    "docutils>=0.8.1,<=0.11",
+    "whoosh>=2.4.0",
+    "celery>=2.2.5",
+    "babel>=0.9.6",
+    "python-dateutil>=1.5.0",
+    "markdown>=2.2.1",
+    "docutils>=0.8.11",
     "mock",
-    "URLObject==2.3.4",
-    "Routes==1.13",
-    "dulwich>=0.9.9,<=0.9.9",
-    "mercurial>=2.9,<3.8",
+    "URLObject>=2.3.4",
+    "Routes>=1.13",
+    "dulwich>=0.9.9",
+    "mercurial>=2.9",
 ]
 
 if sys.version_info < (2, 7):
-    requirements.append("importlib==1.0.1")
+    requirements.append("importlib>=1.0.1")
     requirements.append("unittest2")
     requirements.append("argparse")
 
 if not is_windows:
-    requirements.append("py-bcrypt>=0.3.0,<=0.4")
+    requirements.append("py-bcrypt>=0.3.0")
 
 
 dependency_links = [
