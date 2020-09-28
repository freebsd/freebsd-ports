--- tools/make-release-mail.py.orig	2012-11-12 14:13:18 UTC
+++ tools/make-release-mail.py
@@ -50,14 +50,14 @@ GIT_URL = 'http://cgit.freedesktop.org/telepathy'
 def main(package, version, news_path):
     release_name, details = extract_description(package, version, news_path)
 
-    print """
+    print("""
 %(release_name)s
 
 tarball: %(base_url)s/%(package)s/%(package)s-%(version)s.tar.gz
 signature: %(base_url)s/%(package)s/%(package)s-%(version)s.tar.gz.asc
 git: %(git_url)s/%(package)s
 
-%(details)s""".strip().rstrip() % {
+%(details)s""").strip().rstrip() % {
         'base_url': BASE_URL,
         'git_url': GIT_URL,
         'package': package,
