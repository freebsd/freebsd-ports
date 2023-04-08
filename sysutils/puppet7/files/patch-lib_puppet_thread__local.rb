--- lib/puppet/thread_local.rb.orig	2023-04-08 20:42:06 UTC
+++ lib/puppet/thread_local.rb
@@ -1,3 +1,4 @@
+gem 'concurrent-ruby', '< 1.2.0'
 require 'concurrent'
 
 # We want to use the pure Ruby implementation even on JRuby. If we use the Java
