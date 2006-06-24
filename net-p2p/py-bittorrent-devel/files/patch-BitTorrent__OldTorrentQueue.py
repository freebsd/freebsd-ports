--- ./BitTorrent/OldTorrentQueue.py.orig	Mon Jun 12 22:45:49 2006
+++ ./BitTorrent/OldTorrentQueue.py	Wed Jun 21 23:57:08 2006
@@ -20,7 +20,7 @@
 
 
 from BitTorrent.platform import bttime
-from BitTorrent.download import Feedback, Multitorrent
+from BitTorrent.MultiTorrent import Feeback, MultiTorrent
 from BitTorrent.bencode import bdecode
 from BitTorrent.ConvertedMetainfo import ConvertedMetainfo
 from BitTorrent.prefs import Preferences
