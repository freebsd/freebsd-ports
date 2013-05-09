--- subliminal/services/thesubdb.py.orig	2013-01-17 20:47:10.000000000 +0100
+++ subliminal/services/thesubdb.py	2013-04-27 23:47:24.000000000 +0200
@@ -40,7 +40,7 @@
         return self.query(video.path, video.hashes['TheSubDB'], languages)
 
     def query(self, filepath, moviehash, languages):
-        r = self.session.get(self.server_url, params={'action': 'search', 'hash': moviehash})
+        r = self.session.get(self.server_url, timeout=self.timeout, params={'action': 'search', 'hash': moviehash})
         if r.status_code == 404:
             logger.debug(u'Could not find subtitles for hash %s' % moviehash)
             return []
