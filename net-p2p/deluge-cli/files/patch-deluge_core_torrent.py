Vendor fix for https://dev.deluge-torrent.org/ticket/3279

===================================================================
--- deluge/core/torrent.py	(revision 8b62e50eb8bf81a177c4d62484a44b766c6f54a6)
+++ deluge/core/torrent.py	(revision 4b29436cd5eabf9af271f3fa6250cd7c91cdbc9d)
@@ -811,5 +811,9 @@
                 continue
 
-            client = decode_bytes(peer.client)
+            try:
+                client = decode_bytes(peer.client)
+            except UnicodeDecodeError:
+                # libtorrent on Py3 can raise UnicodeDecodeError for peer_info.client
+                client = 'unknown'
 
             try:
