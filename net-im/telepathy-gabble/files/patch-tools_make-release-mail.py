--- tools/make-release-mail.py.orig	2013-10-09 23:29:36 UTC
+++ tools/make-release-mail.py
@@ -28,8 +28,8 @@ def extract_description(package, version, news_path):
                 break
 
         # Skip the ====== line, and the first blank line
-        lines.next()
-        lines.next()
+        next(lines)
+        next(lines)
 
         got_release_name = False
 
@@ -59,7 +59,7 @@ GIT_URL = 'http://cgit.freedesktop.org/telepathy'
 def main(package, version, news_path):
     release_name, details = extract_description(package, version, news_path)
 
-    print """
+    print("""
 %(release_name)s
 
 tarball: %(base_url)s/%(package)s/%(package)s-%(version)s.tar.gz
@@ -73,14 +73,14 @@ git: %(git_url)s/%(package)s
         'version': version,
         'release_name': release_name,
         'details': details,
-    }
+    })
 
 if __name__ == '__main__':
     try:
         package, version, news_path = sys.argv[1:]
 
         main(package, version, news_path)
-    except ValueError, e:
+    except ValueError as e:
         sys.stderr.write(
             'Usage: %s package-name package.version.number path/to/NEWS\n' %
             sys.argv[0])
