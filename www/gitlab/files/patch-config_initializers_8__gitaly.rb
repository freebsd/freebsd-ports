--- config/initializers/8_gitaly.rb.orig	2017-06-07 20:58:14 UTC
+++ config/initializers/8_gitaly.rb
@@ -1,2 +1 @@
 # Make sure we initialize a Gitaly channel before Sidekiq starts multi-threaded execution.
-Gitlab::GitalyClient.channel unless Rails.env.test?
