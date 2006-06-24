--- ./launchmany-console.py.orig	Mon Jun 12 22:46:19 2006
+++ ./launchmany-console.py	Wed Jun 21 23:57:08 2006
@@ -34,10 +34,10 @@
             self.message(_("no torrents"))
         for x in data:
             ( name, status, progress, peers, seeds, seedsmsg, dist,
-              uprate, dnrate, upamt, dnamt, size, t, msg ) = x
-            print '"%s": "%s" (%s) - %sP%s%s%.3fD u%0.1fK/s-d%0.1fK/s u%dK-d%dK "%s"' % (
+              uprate, dnrate, upamt, dnamt, size, t ) = x
+            print '"%s": "%s" (%s) - %sP%s%s%.3fD u%0.1fK/s-d%0.1fK/s u%dK-d%dK' % (
                         name, status, progress, peers, seeds, seedsmsg, dist,
-                        uprate/1000, dnrate/1000, upamt/1024, dnamt/1024, msg)
+                        uprate/1000, dnrate/1000, upamt/1024, dnamt/1024)
         return False
 
     def message(self, s):
