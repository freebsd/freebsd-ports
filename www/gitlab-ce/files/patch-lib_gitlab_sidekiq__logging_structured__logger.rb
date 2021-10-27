--- lib/gitlab/sidekiq_logging/structured_logger.rb.orig	2021-10-26 19:13:52 UTC
+++ lib/gitlab/sidekiq_logging/structured_logger.rb
@@ -2,6 +2,7 @@
 
 require 'active_record'
 require 'active_record/log_subscriber'
+require 'sidekiq/job_logger'
 
 module Gitlab
   module SidekiqLogging
