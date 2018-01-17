--- config/puma.rb.orig	2017-05-22 21:15:56 UTC
+++ config/puma.rb
@@ -1,6 +1,8 @@
 threads_count = ENV.fetch('MAX_THREADS') { 5 }.to_i
 threads threads_count, threads_count
 
+pidfile '/var/run/mastodon/mastodon_web.pid'
+
 if ENV['SOCKET'] then
   bind 'unix://' + ENV['SOCKET']
 else
