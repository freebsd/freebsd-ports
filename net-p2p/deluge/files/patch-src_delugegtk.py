Index: /trunk/src/delugegtk.py
===================================================================
--- src/delugegtk.py (revision 288)
+++ src/delugegtk.py (revision 289)
@@ -695,6 +695,5 @@
 				self.wtree.get_widget("toolbutton_pause").set_stock_id(gtk.STOCK_MEDIA_PAUSE)
 		except KeyError:
-			pass	
-		self.saved_peer_info = None
+			pass
 		
 
@@ -744,8 +743,5 @@
 			unique_id = self.get_selected_torrent()
 			
-			self.saved_peer_info = self.manager.get_torrent_peer_info(unique_id)
-			
-			
-			new_peer_info = self.saved_peer_info
+			new_peer_info = self.manager.get_torrent_peer_info(unique_id)
 			
 			new_ips = {}
@@ -782,4 +778,12 @@
 											dcommon.frate(peer["download_speed"]), 
 											dcommon.frate(peer["upload_speed"])])
+			#print new_ips
+			#print curr_ips
+			#print new_peer_info
+			del new_peer_info
+			del new_ips
+			del curr_ips
+			
+			
 								
 		elif tab == 2: #File List
