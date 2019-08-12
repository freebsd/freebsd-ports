# Fix Python 3 build

--- sphinxcontrib/bitbucket.py.orig	2019-08-11 09:19:09 UTC
+++ sphinxcontrib/bitbucket.py
@@ -23,7 +23,7 @@ def make_link_node(rawtext, app, type, slug, options):
         base = app.config.bitbucket_project_url
         if not base:
             raise AttributeError
-    except AttributeError, err:
+    except AttributeError as err:
         raise ValueError('bitbucket_project_url configuration value is not set (%s)' % str(err))
     #
     slash = '/' if base[-1] != '/' else ''
