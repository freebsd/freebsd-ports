--- ./urlgrabber/grabber.py.orig	2009-09-25 18:19:50.000000000 +0200
+++ ./urlgrabber/grabber.py	2013-08-15 17:18:28.000000000 +0200
@@ -1052,7 +1052,7 @@
         self._reget_length = 0
         self._prog_running = False
         self._error = (None, None)
-        self.size = None
+        self.size = 0
         self._do_open()
         
         
@@ -1127,6 +1127,9 @@
         if not opts:
             opts = self.opts
 
+        # keepalives
+        if not opts.keepalive:
+            self.curl_obj.setopt(pycurl.FORBID_REUSE, 1)
 
         # defaults we're always going to set
         self.curl_obj.setopt(pycurl.NOPROGRESS, False)
@@ -1158,7 +1161,8 @@
                 self.curl_obj.setopt(pycurl.CAPATH, opts.ssl_ca_cert)
                 self.curl_obj.setopt(pycurl.CAINFO, opts.ssl_ca_cert)
             self.curl_obj.setopt(pycurl.SSL_VERIFYPEER, opts.ssl_verify_peer)
-            self.curl_obj.setopt(pycurl.SSL_VERIFYHOST, opts.ssl_verify_host)
+            if opts.ssl_verify_host: # 1 is meaningless to curl
+                self.curl_obj.setopt(pycurl.SSL_VERIFYHOST, 2)
             if opts.ssl_key:
                 self.curl_obj.setopt(pycurl.SSLKEY, opts.ssl_key)
             if opts.ssl_key_type:
@@ -1299,6 +1303,12 @@
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
@@ -1536,7 +1546,8 @@
         if self.opts.size: # if we set an opts size use that, no matter what
             max_size = self.opts.size
         if not max_size: return False # if we have None for all of the Max then this is dumb
-        if cur > max_size + max_size*.10:
+
+        if cur > int(float(max_size) * 1.10):
 
             msg = _("Downloaded more than max size for %s: %s > %s") \
                         % (self.url, cur, max_size)
