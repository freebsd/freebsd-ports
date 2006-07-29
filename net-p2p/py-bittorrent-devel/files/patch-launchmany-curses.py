--- ./launchmany-curses.py.orig	Wed Jul 12 02:18:54 2006
+++ ./launchmany-curses.py	Fri Jul 28 23:42:45 2006
@@ -18,6 +18,7 @@
 
 DOWNLOAD_SCROLL_RATE = 1
 
+import logging
 import sys, os
 from threading import Event
 from time import time, localtime, strftime
@@ -101,7 +102,7 @@
     def winch_handler(self, signum, stackframe):
         self.changeflag.set()
         curses.endwin()
-        self.scrwin.refresh()
+        self.scrwin.noutrefresh()
         self.scrwin = curses.newwin(0, 0, 0, 0)
         self._remake_window()
         self._display_messages()
@@ -120,22 +121,26 @@
         self.mainpan = curses.panel.new_panel(self.mainwin)
         self.mainwin.scrollok(0)
         self.mainwin.nodelay(1)
+        self.mainwin.clearok(1)
 
         self.headerwin = curses.newwin(1, self.mainwinw+1,
                                        1, self.mainwinx)
         self.headerpan = curses.panel.new_panel(self.headerwin)
         self.headerwin.scrollok(0)
+        self.headerwin.clearok(0)
 
         self.totalwin = curses.newwin(1, self.mainwinw+1,
                                       self.mainwinh+1, self.mainwinx)
         self.totalpan = curses.panel.new_panel(self.totalwin)
         self.totalwin.scrollok(0)
+        self.totalwin.clearok(0)
 
         self.statuswinh = self.scrh-4-self.mainwinh
         self.statuswin = curses.newwin(self.statuswinh, self.mainwinw+1,
                                        self.mainwinh+3, self.mainwinx)
         self.statuspan = curses.panel.new_panel(self.statuswin)
         self.statuswin.scrollok(0)
+        self.statuswin.clearok(1)
 
         try:
             self.scrwin.border(ord('|'),ord('|'),ord('-'),ord('-'),ord(' '),ord(' '),ord(' '),ord(' '))
@@ -277,7 +282,8 @@
 
 
 def LaunchManyWrapper(scrwin, config):
-    LaunchMany(config, CursesDisplayer(scrwin), 'launchmany-curses')
+    d = CursesDisplayer(scrwin)
+    LaunchMany(config, d, 'launchmany-curses')
 
 
 if __name__ == '__main__':
@@ -306,7 +312,7 @@
                 platform.decode_from_filesystem(torrent_dir)
         else:
             torrent_dir = config['torrent_dir']
-            torrent_dir,bad = platform.encode_from_filesystem(torrent_dir)
+            torrent_dir,bad = platform.encode_for_filesystem(torrent_dir)
             if bad:
               raise BTFailure(_("Warning: ")+config['torrent_dir']+
                               _(" is not a directory"))
