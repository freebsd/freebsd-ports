--- subliminal/services/subswiki.py.orig	2013-01-17 20:47:10.000000000 +0100
+++ subliminal/services/subswiki.py	2013-04-27 23:44:34.000000000 +0200
@@ -55,7 +55,7 @@
             if isinstance(request_series, unicode):
                 request_series = request_series.encode('utf-8')
             logger.debug(u'Getting subtitles for %s season %d episode %d with languages %r' % (series, season, episode, languages))
-            r = self.session.get('%s/serie/%s/%s/%s/' % (self.server_url, urllib.quote(request_series), season, episode))
+            r = self.session.get('%s/serie/%s/%s/%s/' % (self.server_url, urllib.quote(request_series), season, episode), timeout=self.timeout)
             if r.status_code == 404:
                 logger.debug(u'Could not find subtitles for %s season %d episode %d with languages %r' % (series, season, episode, languages))
                 return []
@@ -64,7 +64,7 @@
             if isinstance(request_movie, unicode):
                 request_movie = request_movie.encode('utf-8')
             logger.debug(u'Getting subtitles for %s (%d) with languages %r' % (movie, year, languages))
-            r = self.session.get('%s/film/%s_(%d)' % (self.server_url, urllib.quote(request_movie), year))
+            r = self.session.get('%s/film/%s_(%d)' % (self.server_url, urllib.quote(request_movie), year), timeout=self.timeout)
             if r.status_code == 404:
                 logger.debug(u'Could not find subtitles for %s (%d) with languages %r' % (movie, year, languages))
                 return []
