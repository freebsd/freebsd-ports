--- hmap.py.orig	Wed Apr  9 14:47:16 2003
+++ hmap.py	Wed Apr  9 14:50:45 2003
@@ -859,7 +859,7 @@
     sys.exit()
 
 known_servers = []
-for f in glob.glob('known.servers/*'):
+for f in glob.glob('PREFIX/share/hmap/*'):
     ksf = file(f)
     ks = eval(ksf.read())
     known_servers.append(ks)
