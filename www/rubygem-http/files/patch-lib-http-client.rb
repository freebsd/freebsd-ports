Obtained from:	https://github.com/httprb/http.rb/commit/64fc52ad7e1bf87bc7a19c89c90d41e42ab90edb

--- lib/http/client.rb.orig	2015-03-02 22:55:00.234280000 +0800
+++ lib/http/client.rb	2015-03-02 22:58:58.379266200 +0800
@@ -1,6 +1,6 @@
 require 'cgi'
 require 'uri'
-require 'form_data'
+require 'http/form_data'
 require 'http/options'
 require 'http/redirector'
 
@@ -132,7 +132,7 @@
       when opts.body
         opts.body
       when opts.form
-        form = FormData.create opts.form
+        form = HTTP::FormData.create opts.form
         headers['Content-Type']   ||= form.content_type
         headers['Content-Length'] ||= form.content_length
         form.to_s
