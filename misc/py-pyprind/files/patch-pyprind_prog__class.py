--- pyprind/prog_class.py.orig	2017-03-18 12:03:55 UTC
+++ pyprind/prog_class.py
@@ -91,6 +91,9 @@ class Prog():
                 supported = ('PYCHARM_HOSTED' in os.environ or
                              os.isatty(sys.stdout.fileno()))
 
+            except AttributeError:
+                supported = False
+
             # a fix for IPython notebook "IOStream has no fileno."
             except(UnsupportedOperation):
                 supported = True
