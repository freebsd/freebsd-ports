--- subliminal/services/subtitulos.py.orig	2013-01-17 20:47:10.000000000 +0100
+++ subliminal/services/subtitulos.py	2013-04-27 23:45:04.000000000 +0200
@@ -54,7 +54,7 @@
         if isinstance(request_series, unicode):
             request_series = unicodedata.normalize('NFKD', request_series).encode('ascii', 'ignore')
         logger.debug(u'Getting subtitles for %s season %d episode %d with languages %r' % (series, season, episode, languages))
-        r = self.session.get('%s/%s/%sx%.2d' % (self.server_url, urllib.quote(request_series), season, episode))
+        r = self.session.get('%s/%s/%sx%.2d' % (self.server_url, urllib.quote(request_series), season, episode), timeout=self.timeout)
         if r.status_code == 404:
             logger.debug(u'Could not find subtitles for %s season %d episode %d with languages %r' % (series, season, episode, languages))
             return []
