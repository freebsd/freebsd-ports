--- src/lib/utils.py.orig	Thu Jul 15 15:15:58 2004
+++ src/lib/utils.py	Mon Aug 16 22:26:08 2004
@@ -162,7 +162,7 @@
         return os.environ["STRAW_DATA"]
     h, t = os.path.split(os.path.split(os.path.abspath(sys.argv[0]))[0])
     if t == 'bin':
-        fp = os.path.join(h, 'share', 'straw')
+        fp = os.path.join(h, 'share', 'gnome', 'straw')
         if os.path.isdir(fp):
             return fp
         fp = os.path.join(h, 'lib', 'straw')
