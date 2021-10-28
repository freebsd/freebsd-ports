--- lib/gitlab/sidekiq_logging/json_formatter.rb.orig	2021-10-27 21:47:49 UTC
+++ lib/gitlab/sidekiq_logging/json_formatter.rb
@@ -2,6 +2,7 @@
 
 # This is needed for sidekiq-cluster
 require 'json'
+require 'sidekiq/job_retry'
 
 module Gitlab
   module SidekiqLogging
