--- ./BitTorrent/AutoUpdateButler.py.orig	Mon May  7 05:41:38 2007
+++ ./BitTorrent/AutoUpdateButler.py	Mon May  7 05:42:02 2007
@@ -300,7 +300,7 @@
 
     def _check_signature(self, torrentfile, signature):
         """Check the torrent file's signature using the public key."""
-        public_key_file = open(os.path.join(doc_root, 'public.key'), 'rb')
+        public_key_file = open(os.path.join(%%DATADIR%%, 'public.key'), 'rb')
         public_key = pickle.load(public_key_file)
         public_key_file.close()
         h = sha(torrentfile).digest()
