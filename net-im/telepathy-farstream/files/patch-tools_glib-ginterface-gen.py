--- tools/glib-ginterface-gen.py.orig	2020-06-17 05:47:06 UTC
+++ tools/glib-ginterface-gen.py
@@ -748,7 +748,7 @@ class Generator(object):
 
 
 def cmdline_error():
-    print """\
+    print("""\
 usage:
     gen-ginterface [OPTIONS] xmlfile Prefix_
 options:
@@ -769,6 +769,7 @@ options:
         and return some sort of "not implemented" error via
             dbus_g_method_return_error (context, ...)
 """
+)
     sys.exit(1)
 
 
