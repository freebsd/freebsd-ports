Backported from upstream repo: http://trac.edgewall.org/changeset/11683
See PR 181419 for details.

--- trac/wiki/formatter.py.orig        2013-02-01 08:47:41.000000000 +0800
+++ trac/wiki/formatter.py 2013-08-20 14:24:46.982232000 +0800
@@ -575,7 +575,7 @@
         ns = fullmatch.group('snsbr')
         target = unquote_label(fullmatch.group('stgtbr'))
         match = match[1:-1]
-        return '&lt;%s&gt;' % \
+        return u'&lt;%s&gt;' % \
                 self._make_link(ns, target, match, match, fullmatch)

     def _shref_formatter(self, match, fullmatch):
