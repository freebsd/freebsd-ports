diff --git setup.py setup.py
index 3e48554..2ff6cd7 100644
--- setup.py
+++ setup.py
@@ -33,24 +33,24 @@ __platform__ = platform.system()
 is_windows = __platform__ in _get_meta_var('PLATFORM_WIN', _metadata)
 
 requirements = [
-    "waitress==0.8.1",
-    "webob==1.0.8",
-    "webtest==1.4.3",
-    "Pylons==1.0.0",
-    "Beaker==1.6.4",
-    "WebHelpers==1.3",
-    "formencode==1.2.4",
-    "SQLAlchemy==0.7.9",
-    "Mako==0.7.3",
+    "waitress>=0.8.1",
+    "webob>=1.0.8",
+    "webtest>=1.4.3",
+    "Pylons>=1.0.0",
+    "Beaker>=1.6.4",
+    "WebHelpers>=1.3",
+    "formencode>=1.2.4",
+    "SQLAlchemy>=0.7.9",
+    "Mako>=0.7.3",
     "pygments>=1.5",
-    "whoosh>=2.4.0,<2.5",
-    "celery>=2.2.5,<2.3",
+    "whoosh>=2.4.0",
+    "celery>=2.2.5",
     "babel",
-    "python-dateutil>=1.5.0,<2.0.0",
+    "python-dateutil>=1.5.0",
     "dulwich>=0.8.7,<0.9.0",
-    "markdown==2.2.1",
-    "docutils==0.8.1",
-    "simplejson==2.5.2",
+    "markdown>=2.2.1",
+    "docutils>=0.8.1",
+    "simplejson>=2.5.2",
     "mock",
 ]
 
@@ -65,7 +65,7 @@ if is_windows:
     requirements.append("mercurial==2.4.2")
 else:
     requirements.append("py-bcrypt")
-    requirements.append("mercurial==2.4.2")
+    requirements.append("mercurial>=2.4.2")
 
 
 dependency_links = [
