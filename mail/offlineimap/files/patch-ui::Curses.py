--- offlineimap/ui/Curses.py	(original)
+++ offlineimap/ui/Curses.py	Fri Jan 10 11:47:36 2003
@@ -29,12 +29,18 @@
 
 class CursesUtil:
     def __init__(self):
-        self.pairs = {self._getpairindex(curses.COLOR_WHITE,
-                                         curses.COLOR_BLACK): 0}
-        self.start()
-        self.nextpair = 1
         self.pairlock = Lock()
         self.iolock = MultiLock()
+        self.start()
+
+    def initpairs(self):
+        self.pairlock.acquire()
+        try:
+            self.pairs = {self._getpairindex(curses.COLOR_WHITE,
+                                             curses.COLOR_BLACK): 0}
+            self.nextpair = 1
+        finally:
+            self.pairlock.release()
 
     def lock(self):
         self.iolock.acquire()
@@ -63,6 +69,8 @@
         return '%d/%d' % (fg,bg)
 
     def getpair(self, fg, bg):
+        if not self.has_color:
+            return 0
         pindex = self._getpairindex(fg, bg)
         self.pairlock.acquire()
         try:
@@ -96,6 +104,7 @@
         self.stdscr.clear()
         self.stdscr.refresh()
         (self.height, self.width) = self.stdscr.getmaxyx()
+        self.initpairs()
 
     def stop(self):
         if not hasattr(self, 'stdscr'):
@@ -200,7 +209,10 @@
 
     def display(self):
         def lockedstuff():
-            self.window.addstr(self.y, self.x, '.', self.color)
+            if self.getcolor() == 'black':
+                self.window.addstr(self.y, self.x, ' ', self.color)
+            else:
+                self.window.addstr(self.y, self.x, '.', self.color)
             self.c.stdscr.move(self.c.height - 1, self.c.width - 1)
             self.window.refresh()
         self.c.locked(lockedstuff)
@@ -406,9 +418,12 @@
             s.c.unlock()
 
     def setupwindow_drawbanner(s):
-        s.bannerwindow.bkgd(' ', curses.A_BOLD | \
-                            s.c.getpair(curses.COLOR_WHITE,
-                                        curses.COLOR_BLUE))
+        if s.c.has_color:
+            color = s.c.getpair(curses.COLOR_WHITE, curses.COLOR_BLUE) | \
+                    curses.A_BOLD
+        else:
+            color = curses.A_REVERSE
+        s.bannerwindow.bkgd(' ', color) # Fill background with that color
         s.bannerwindow.addstr("%s %s" % (version.productname,
                                          version.versionstr))
         s.bannerwindow.addstr(0, s.bannerwindow.getmaxyx()[1] - len(version.copyright) - 1,
@@ -417,7 +432,11 @@
         s.bannerwindow.noutrefresh()
 
     def setupwindow_drawlog(s):
-        s.logwindow.bkgd(' ', s.c.getpair(curses.COLOR_WHITE, curses.COLOR_BLACK))
+        if s.c.has_color:
+            color = s.c.getpair(curses.COLOR_WHITE, curses.COLOR_BLACK)
+        else:
+            color = curses.A_NORMAL
+        s.logwindow.bkgd(' ', color)
         for line, color in s.text:
             s.logwindow.addstr("\n" + line, color)
         s.logwindow.noutrefresh()
@@ -501,7 +520,7 @@
     x = Blinkenlights(None)
     x.init_banner()
     import time
-    time.sleep(10)
+    time.sleep(5)
     x.c.stop()
     fgs = {'black': curses.COLOR_BLACK, 'red': curses.COLOR_RED,
            'green': curses.COLOR_GREEN, 'yellow': curses.COLOR_YELLOW,
@@ -536,7 +555,7 @@
     win4.refresh()
     x.stdscr.refresh()
     import time
-    time.sleep(40)
+    time.sleep(5)
     x.stop()
     print x.has_color
     print x.height
