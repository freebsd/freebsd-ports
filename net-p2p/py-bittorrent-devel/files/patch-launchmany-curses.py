--- ./launchmany-curses.py.orig	Mon Jun 12 22:46:19 2006
+++ ./launchmany-curses.py	Wed Jun 21 23:57:08 2006
@@ -18,6 +18,7 @@
 
 DOWNLOAD_SCROLL_RATE = 1
 
+import logging
 import sys, os
 from threading import Event
 from time import time, localtime, strftime
@@ -99,7 +100,7 @@
     def winch_handler(self, signum, stackframe):
         self.changeflag.set()
         curses.endwin()
-        self.scrwin.refresh()
+        self.scrwin.noutrefresh()
         self.scrwin = curses.newwin(0, 0, 0, 0)
         self._remake_window()
         self._display_messages()
@@ -118,22 +119,26 @@
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
@@ -199,7 +204,7 @@
                 if self._display_line(''):
                     break
             ( name, status, progress, peers, seeds, seedsmsg, dist,
-              uprate, dnrate, upamt, dnamt, size, t, msg ) = data[ii]
+              uprate, dnrate, upamt, dnamt, size, t ) = data[ii]
             t = fmttime(t)
             if t:
                 status = t
@@ -216,7 +221,7 @@
             else:
                 datastr = '    '+status+' ('+progress+')'
             self._display_line(datastr)
-            self._display_line('    '+ljust(msg,self.mainwinw-4))
+#            self._display_line('    '+ljust(msg,self.mainwinw-4))
             i += 1
 
     def display(self, data):
@@ -236,7 +241,7 @@
         totalup = 0
         totaldn = 0
         for ( name, status, progress, peers, seeds, seedsmsg, dist,
-              uprate, dnrate, upamt, dnamt, size, t, msg ) in data:
+              uprate, dnrate, upamt, dnamt, size, t ) in data:
             totalup += uprate
             totaldn += dnrate
 
