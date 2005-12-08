--- BitTorrent/NewVersion.py.orig	Sun Nov 20 23:10:09 2005
+++ BitTorrent/NewVersion.py	Sun Nov 20 23:10:37 2005
@@ -127,7 +127,7 @@
             self.threadwrap(self.errorfunc, WARNING, '\n'.join(terrors))
 
         if torrentfile and signature:
-            public_key_file = open(os.path.join(doc_root, 'public.key'), 'rb')
+            public_key_file = open(os.path.join(%%DATADIR%%, 'public.key'), 'rb')
             public_key = pickle.load(public_key_file)
             h = sha(torrentfile).digest()
             if public_key.verify(h, signature):
