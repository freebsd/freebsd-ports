--- btdownloadgui.py.orig	Mon Dec 20 20:39:15 2004
+++ btdownloadgui.py	Sat Jan  8 15:16:14 2005
@@ -1507,33 +1507,44 @@
 
         if advanced_ui:
             self.extrabox = gtk.VBox(homogeneous=False)
-
-            self.table = gtk.Table(2, 7, False)
-            self.labels = []
-            lnames = ('peers','seeds','distr','up curr.','down curr.','up prev.','down prev.')
+            #self.extrabox = self.vbox
+            
+            self.up_curr    = FancyLabel('Current up: %s'  , 0)
+            self.down_curr  = FancyLabel('Current down: %s', 0)
+            self.curr_box   = gtk.HBox(homogeneous=True)
+            self.curr_box.pack_start(lalign(self.up_curr  ), expand=True, fill=True)
+            self.curr_box.pack_start(lalign(self.down_curr), expand=True, fill=True)
+            self.extrabox.pack_start(self.curr_box)
             
-            for i, name in enumerate(lnames):
-                label = gtk.Label(name)
-                self.table.attach(label, i, i+1, 0, 1, xpadding = SPACING)
-                label = gtk.Label('-')
-                self.labels.append(label)
-                self.table.attach(label, i, i+1, 1, 2, xpadding = SPACING)
-            self.extrabox.pack_start(self.table)
+            self.up_prev    = FancyLabel('Previous up: %s'    , 0)
+            self.down_prev  = FancyLabel('Previous down: %s'  , 0)
+            self.prev_box   = gtk.HBox(homogeneous=True)
+            self.prev_box.pack_start(lalign(self.up_prev  ), expand=True, fill=True)
+            self.prev_box.pack_start(lalign(self.down_prev), expand=True, fill=True)
+            self.extrabox.pack_start(self.prev_box)
+
+            self.share_ratio = FancyLabel('Share ratio: %0.02f%%', 0)
+            self.extrabox.pack_start(lalign(self.share_ratio))
+
+            self.peer_info = FancyLabel('%s peers, %s seeds',0,0)
+            self.extrabox.pack_start(lalign(self.peer_info))
 
-            # extra info
-            self.elabels = []
-            for i in range(4):
-                label = gtk.Label('-')
-                self.extrabox.pack_start(lalign(label))
-                self.elabels.append(label)
+            self.dist_copies = FancyLabel('Distributed copies: %d; Next: %s', 0, '')
+            self.extrabox.pack_start(lalign(self.dist_copies))
+
+            self.piece_info = FancyLabel('Pieces: %d total, %d complete, %d partial, %d active (%d empty)', *(0,)*5)
+            self.extrabox.pack_start(lalign(self.piece_info))
+
+            self.bad_info = FancyLabel('%d bad pieces + %s in discarded requests', 0, 0)
+            self.extrabox.pack_start(lalign(self.bad_info))
 
+            # extra info
+            
             pl = self.metainfo.piece_length
             tl = self.metainfo.total_bytes
             count, lastlen = divmod(tl, pl)
             self.piece_count = count + (lastlen > 0)
 
-            self.elabels[0].set_text("Share ratio: -")
-
             self.infobox.pack_end(self.extrabox, expand=False, fill=False)
 
 
@@ -1649,31 +1660,34 @@
                                 Rate(statistics['upRate']))
 
         if advanced_ui:
-            self.labels[0].set_text(str(statistics['numPeers']))
+            if self.up_down_ratio is not None:
+                self.share_ratio.set_value(self.up_down_ratio*100)
+
+            num_seeds = statistics['numSeeds']
             if self.seed:
-                statistics['numOldSeeds'] = 0 # !@# XXX
-                self.labels[1].set_text('(%d)' % statistics['numOldSeeds'])
-            else:
-                self.labels[1].set_text(str(statistics['numSeeds']))
-            self.labels[2].set_text(str(statistics['numCopies']))
-            self.labels[3].set_text(str(Size(statistics['upTotal'])))
-            self.labels[4].set_text(str(Size(statistics['downTotal'])))
-            self.labels[5].set_text(str(Size(self.uptotal)))
-            self.labels[6].set_text(str(Size(self.downtotal)))
+                num_seeds = statistics['numOldSeeds'] = 0 # !@# XXX
+
+            self.peer_info.set_value(statistics['numPeers' ],
+                                     num_seeds)
+                                     #statistics['numCopies'], )
+
+            self.up_curr.set_value(str(Size(statistics['upTotal'])))
+            self.down_curr.set_value(str(Size(statistics['downTotal'])))
+
+            self.up_prev.set_value(str(Size(self.uptotal)))
+            self.down_prev.set_value(str(Size(self.downtotal)))
 
-        if advanced_ui:
             # refresh extra info
-            if self.up_down_ratio is not None:
-                self.elabels[0].set_text('Share ratio: %.2f%%' % (self.up_down_ratio*100))
-            self.elabels[1].set_text('Pieces: %d total, %d complete, %d partial, %d active (%d empty)'
-                                     % (self.piece_count                 ,
-                                        statistics['storage_numcomplete'],
-                                        statistics['storage_dirty'],
-                                        statistics['storage_active'],
-                                        statistics['storage_new']))
-            self.elabels[2].set_text('Next distributed copies: ' + ', '.join(["%d:%.1f%%" % (a, int(b*1000)/10) for a, b in zip(itertools.count(int(statistics['numCopies']+1)), statistics['numCopyList'])]))
-            self.elabels[3].set_text('%d bad pieces + %s in discarded requests' % (statistics['storage_numflunked'], Size(statistics['discarded'])))
+            self.piece_info.set_value(self.piece_count,
+                                      statistics['storage_numcomplete'],
+                                      statistics['storage_dirty'],
+                                      statistics['storage_active'],
+                                      statistics['storage_new'] )
 
+            self.dist_copies.set_value( statistics['numCopies'], ', '.join(["%d:%.1f%%" % (a, int(b*1000)/10) for a, b in zip(itertools.count(int(statistics['numCopies']+1)), statistics['numCopyList'])]))
+
+            self.bad_info.set_value(statistics['storage_numflunked'], Size(statistics['discarded']))
+        
         if self.peerlistwindow is not None:
             spew = statistics.get('spew')
             if spew is not None:
