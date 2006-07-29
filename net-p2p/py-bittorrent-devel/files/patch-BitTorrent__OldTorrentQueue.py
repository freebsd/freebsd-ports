--- ./BitTorrent/OldTorrentQueue.py.orig	Wed Jul 12 02:18:22 2006
+++ ./BitTorrent/OldTorrentQueue.py	Sat Jul 22 17:42:24 2006
@@ -20,7 +20,7 @@
 
 
 from BitTorrent.platform import bttime
-from BitTorrent.download import Feedback, Multitorrent
+from BitTorrent.MultiTorrent import Feeback, MultiTorrent
 from BitTorrent.bencode import bdecode
 from BitTorrent.ConvertedMetainfo import ConvertedMetainfo
 from BitTorrent.prefs import Preferences
