--- MoinMoin/parser/wiki.py.orig	Wed Jan  9 21:20:17 2002
+++ MoinMoin/parser/wiki.py	Wed Jan  9 21:22:55 2002
@@ -388,7 +388,7 @@
     def replace(self, match):
         #hit = filter(lambda g: g[1], match.groupdict().items())
         for type, hit in match.groupdict().items():
-            if hit is not None:
+            if hit is not None and type != 'hmarker':
                 ##print "###", cgi.escape(`type`), cgi.escape(`hit`), "###"
                 if self.in_pre and type not in ['pre', 'ent']:
                     return self.highlight_text(hit)
