--- subliminal/services/bierdopje.py.orig	2013-01-17 20:47:10.000000000 +0100
+++ subliminal/services/bierdopje.py	2013-04-27 23:42:59.000000000 +0200
@@ -45,7 +45,7 @@
 
     @cachedmethod
     def get_show_id(self, series):
-        r = self.session.get('%sGetShowByName/%s' % (self.server_url, urllib.quote(series.lower())))
+        r = self.session.get('%sGetShowByName/%s' % (self.server_url, urllib.quote(series.lower())), timeout=self.timeout)
         if r.status_code != 200:
             logger.error(u'Request %s returned status code %d' % (r.url, r.status_code))
             return None
@@ -78,7 +78,7 @@
         subtitles = []
         for language in languages:
             logger.debug(u'Getting subtitles for %s %d season %d episode %d with language %s' % (request_source, request_id, season, episode, language.alpha2))
-            r = self.session.get('%sGetAllSubsFor/%s/%s/%s/%s/%s' % (self.server_url, request_id, season, episode, language.alpha2, request_is_tvdbid))
+            r = self.session.get('%sGetAllSubsFor/%s/%s/%s/%s/%s' % (self.server_url, request_id, season, episode, language.alpha2, request_is_tvdbid), timeout=self.timeout)
             if r.status_code != 200:
                 logger.error(u'Request %s returned status code %d' % (r.url, r.status_code))
                 return []
