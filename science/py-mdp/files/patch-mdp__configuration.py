--- ./mdp/configuration.py.orig	2012-06-20 21:46:00.000000000 +1000
+++ ./mdp/configuration.py	2012-06-20 21:52:56.000000000 +1000
@@ -360,7 +360,7 @@
     try:
         import svm as libsvm
         libsvm.libsvm
-    except ImportError, exc:
+    except (ImportError, OSError) as exc:
         config.ExternalDepFailed('libsvm', exc)
     except AttributeError, exc:
         config.ExternalDepFailed('libsvm', 'libsvm version >= 2.91 required')
