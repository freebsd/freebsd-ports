--- src/lib/Main.py.orig	Thu Nov 13 21:57:57 2003
+++ src/lib/Main.py	Thu Nov 13 21:58:51 2003
@@ -360,7 +360,7 @@
         return os.environ["STRAW_DATA"]
     h, t = os.path.split(os.path.split(os.path.abspath(sys.argv[0]))[0])
     if t == 'bin':
-        fp = os.path.join(h, 'share', 'straw')
+        fp = os.path.join(h, 'share', 'gnome', 'straw')
         if os.path.isdir(fp):
             return fp
         fp = os.path.join(h, 'lib', 'straw')
