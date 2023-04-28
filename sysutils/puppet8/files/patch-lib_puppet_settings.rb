--- lib/puppet/settings.rb.orig	2023-04-08 20:42:13 UTC
+++ lib/puppet/settings.rb
@@ -4,6 +4,7 @@ require_relative '../puppet/util/watched_file'
 require_relative '../puppet/util/command_line/puppet_option_parser'
 require 'forwardable'
 require 'fileutils'
+gem 'concurrent-ruby', '< 1.2.0'
 require 'concurrent'
 
 # The class for handling configuration files.
