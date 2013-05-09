--- subliminal/services/tvsubtitles.py.orig	2013-01-17 20:47:10.000000000 +0100
+++ subliminal/services/tvsubtitles.py	2013-04-27 23:48:50.000000000 +0200
@@ -52,7 +52,7 @@
 
     @cachedmethod
     def get_likely_series_id(self, name):
-        r = self.session.post('%s/search.php' % self.server_url, data={'q': name})
+        r = self.session.post('%s/search.php' % self.server_url, data={'q': name}, timeout=self.timeout)
         soup = BeautifulSoup(r.content, self.required_features)
         maindiv = soup.find('div', 'left')
         results = []
@@ -70,7 +70,7 @@
         could be found."""
         # download the page of the season, contains ids for all episodes
         episode_id = None
-        r = self.session.get('%s/tvshow-%d-%d.html' % (self.server_url, series_id, season))
+        r = self.session.get('%s/tvshow-%d-%d.html' % (self.server_url, series_id, season),timeout=self.timeout)
         soup = BeautifulSoup(r.content, self.required_features)
         table = soup.find('table', id='table5')
         for row in table.find_all('tr'):
@@ -93,7 +93,7 @@
     # subtitles
     def get_sub_ids(self, episode_id):
         subids = []
-        r = self.session.get('%s/episode-%d.html' % (self.server_url, episode_id))
+        r = self.session.get('%s/episode-%d.html' % (self.server_url, episode_id), timeout=self.timeout)
         epsoup = BeautifulSoup(r.content, self.required_features)
         for subdiv in epsoup.find_all('a'):
             if 'href' not in subdiv.attrs or not subdiv['href'].startswith('/subtitle'):
