--- src/lib/Main.py.orig	Mon Apr 26 12:17:31 2004
+++ src/lib/Main.py	Sun May  2 15:30:14 2004
@@ -417,7 +417,7 @@
         gtk.main()
 
     def quit(self):
-        gtk.mainquit()
+        gtk.main_quit()
         self._itemstore.stop()
         return
 
@@ -480,7 +480,7 @@
         return os.environ["STRAW_DATA"]
     h, t = os.path.split(os.path.split(os.path.abspath(sys.argv[0]))[0])
     if t == 'bin':
-        fp = os.path.join(h, 'share', 'straw')
+        fp = os.path.join(h, 'share', 'gnome', 'straw')
         if os.path.isdir(fp):
             return fp
         fp = os.path.join(h, 'lib', 'straw')
