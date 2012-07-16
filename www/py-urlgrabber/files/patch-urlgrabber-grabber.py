From: Seth Vidal <skvidal@fedoraproject.org>
Date: Fri, 25 Sep 2009 20:16:08 +0000 (-0400)
Subject: - fileobject size = 0 not None
X-Git-Url: http://yum.baseurl.org/gitweb?p=urlgrabber.git;a=commitdiff_plain;h=f4e57ece7ded0f7ad83c8a40fe8423fab7812264;hp=926062a18852bc73686a5ef60307526841df8a32

- fileobject size = 0 not None
- if the filesize is small enough we could receive the whole thing in on chunk
  and our max size message would never get out - so we make sure
- make sure we multiply correctly b/c python is anal
---

diff --git a/urlgrabber/grabber.py b/urlgrabber/grabber.py
index e090e90..c4916d5 100644
--- urlgrabber/grabber.py
+++ urlgrabber/grabber.py
@@ -1052,7 +1052,7 @@ class PyCurlFileObject():
         self._reget_length = 0
         self._prog_running = False
         self._error = (None, None)
-        self.size = None
+        self.size = 0
         self._do_open()
         
         
@@ -1299,6 +1299,12 @@ class PyCurlFileObject():
             err.code = code
             err.exception = e
             raise err
+        else:
+            if self._error[1]:
+                msg = self._error[1]
+                err = URLGRabError(14, msg)
+                err.url = self.url
+                raise err
 
     def _do_open(self):
         self.curl_obj = _curl_cache
@@ -1536,7 +1542,8 @@ class PyCurlFileObject():
         if self.opts.size: # if we set an opts size use that, no matter what
             max_size = self.opts.size
         if not max_size: return False # if we have None for all of the Max then this is dumb
-        if cur > max_size + max_size*.10:
+
+        if cur > int(float(max_size) * 1.10):
 
             msg = _("Downloaded more than max size for %s: %s > %s") \
                         % (self.url, cur, max_size)
