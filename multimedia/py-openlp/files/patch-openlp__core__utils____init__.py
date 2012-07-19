--- ./openlp/core/utils/__init__.py.orig	2012-07-18 10:20:51.000000000 -0400
+++ ./openlp/core/utils/__init__.py	2012-07-18 10:28:30.000000000 -0400
@@ -172,6 +172,11 @@
             u'Library', u'Application Support', u'openlp')
     else:
         if dir_type == AppLocation.LanguageDir:
+            prefixes = [u'/usr/local', u'/usr']
+            for prefix in prefixes:
+                directory = os.path.join(prefix, u'share', u'openlp')
+                if os.path.exists(directory):
+                    return directory
             return os.path.join(u'/usr', u'share', u'openlp')
         if XDG_BASE_AVAILABLE:
             if dir_type == AppLocation.ConfigDir:
