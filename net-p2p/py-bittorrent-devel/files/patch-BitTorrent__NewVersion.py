--- ./BitTorrent/NewVersion.py.orig	Mon Jun 12 22:45:49 2006
+++ ./BitTorrent/NewVersion.py	Wed Jun 21 23:57:08 2006
@@ -170,7 +170,7 @@
             self.threadwrap(self.errorfunc, logging.WARNING, '\n'.join(terrors))
 
         if torrentfile and signature:
-            public_key_file = open(os.path.join(doc_root, 'public.key'), 'rb')
+            public_key_file = open(os.path.join(%%DATADIR%%, 'public.key'), 'rb')
             public_key = pickle.load(public_key_file)
             h = sha(torrentfile).digest()
             if public_key.verify(h, signature):
