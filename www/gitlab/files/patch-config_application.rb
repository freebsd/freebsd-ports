--- config/application.rb.orig	2025-02-13 06:21:36 UTC
+++ config/application.rb
@@ -1,6 +1,11 @@ require_relative 'boot'
 # frozen_string_literal: true
 require_relative 'boot'
 
+# Required as rubygem-concurrent-ruby version 1.3.5 has remove logger, but is required by active_support
+# The fix has only applied to rails 7.1 and 7.2
+# https://github.com/rails/rails/pull/49372
+require "logger"
+
 # Based on https://github.com/rails/rails/blob/v6.0.1/railties/lib/rails/all.rb
 # Only load the railties we need instead of loading everything
 require 'rails'
