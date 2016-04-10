--- mdp/configuration.py.orig	2016-04-10 17:12:43 UTC
+++ mdp/configuration.py
@@ -388,7 +388,7 @@ def set_configuration():
     try:
         import svm as libsvm
         libsvm.libsvm
-    except ImportError as exc:
+        except (ImportError, OSError) as exc:
         config.ExternalDepFailed('libsvm', exc)
     except AttributeError as exc:
         config.ExternalDepFailed('libsvm', 'libsvm version >= 2.91 required')
