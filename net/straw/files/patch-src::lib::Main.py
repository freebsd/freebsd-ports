--- src/lib/Main.py.orig	Tue Feb 17 13:35:41 2004
+++ src/lib/Main.py	Tue Feb 17 13:36:26 2004
@@ -479,7 +479,7 @@
         return os.environ["STRAW_DATA"]
     h, t = os.path.split(os.path.split(os.path.abspath(sys.argv[0]))[0])
     if t == 'bin':
-        fp = os.path.join(h, 'share', 'straw')
+        fp = os.path.join(h, 'share', 'gnome', 'straw')
         if os.path.isdir(fp):
             return fp
         fp = os.path.join(h, 'lib', 'straw')
