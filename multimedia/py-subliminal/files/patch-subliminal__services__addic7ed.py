--- subliminal/services/addic7ed.py.orig	2013-01-17 20:47:10.000000000 +0100
+++ subliminal/services/addic7ed.py	2013-04-27 23:40:43.000000000 +0200
@@ -48,7 +48,7 @@
     @cachedmethod
     def get_series_id(self, name):
         """Get the show page and cache every show found in it"""
-        r = self.session.get('%s/shows.php' % self.server_url)
+        r = self.session.get('%s/shows.php' % self.server_url, timeout=self.timeout)
         soup = BeautifulSoup(r.content, self.required_features)
         for html_series in soup.select('h3 > a'):
             series_name = html_series.text.lower()
@@ -70,7 +70,7 @@
         except KeyError:
             logger.debug(u'Could not find series id for %s' % series)
             return []
-        r = self.session.get('%s/show/%d&season=%d' % (self.server_url, series_id, season))
+        r = self.session.get('%s/show/%d&season=%d' % (self.server_url, series_id, season), timeout=self.timeout)
         soup = BeautifulSoup(r.content, self.required_features)
         subtitles = []
         for row in soup('tr', {'class': 'epeven completed'}):
@@ -102,7 +102,7 @@
     def download(self, subtitle):
         logger.info(u'Downloading %s in %s' % (subtitle.link, subtitle.path))
         try:
-            r = self.session.get(subtitle.link, headers={'Referer': subtitle.link, 'User-Agent': self.user_agent})
+            r = self.session.get(subtitle.link, timeout=self.timeout, headers={'Referer': subtitle.link})
             soup = BeautifulSoup(r.content, self.required_features)
             if soup.title is not None and u'Addic7ed.com' in soup.title.text.strip():
                 raise DownloadFailedError('Download limit exceeded')
