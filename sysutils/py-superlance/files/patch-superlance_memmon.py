FreeBSD's ps(1) only supports adding an equals sign to the last
keyword, the original command returns a list of pid with non-empty
header on FreeBSD.

--- superlance/memmon.py.orig	2017-10-25 04:36:57 UTC
+++ superlance/memmon.py
@@ -114,7 +114,7 @@ class Memmon:
         self.stdout = sys.stdout
         self.stderr = sys.stderr
         self.pscommand = 'ps -orss= -p %s'
-        self.pstreecommand = 'ps ax -o "pid= ppid= rss="'
+        self.pstreecommand = 'ps ax -o pid= -o ppid= -o rss='
         self.mailed = False # for unit tests
 
     def runforever(self, test=False):
