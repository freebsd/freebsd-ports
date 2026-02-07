--- mikutter.rb.orig	2020-02-04 02:25:25 UTC
+++ mikutter.rb
@@ -1,6 +1,6 @@
 #!/bin/sh
 # -*- coding: utf-8 -*-
-exec ruby -x "$0" "$@"
+exec %%RUBY_WITH_SUFFIX%% -x "$0" "$@"
 #!ruby
 =begin rdoc
 = mikutter - simple, powerful and moeful Mastodon client
@@ -13,7 +13,7 @@ http://opensource.org/licenses/mit-license.php
 =end
 module Mikutter; end
 
-require_relative 'core/boot/option'
+require_relative '%%RUBY_SITELIBDIR%%/mikutter/core/boot/option'
 Mopt.parse exec_command: true
 
 if !ENV['DISABLE_BUNDLER_SETUP'] || ['', '0'].include?(ENV['DISABLE_BUNDLER_SETUP'].to_s)
@@ -33,7 +33,7 @@ require 'webrick'
 require 'thread'
 require 'fileutils'
 
-require_relative 'core/miquire'
+require_relative '%%RUBY_SITELIBDIR%%/mikutter/core/miquire'
 
 require 'lib/diva_hacks'
 require 'lib/lazy'
@@ -42,7 +42,7 @@ require 'lib/timelimitedqueue'
 require 'lib/uithreadonly'
 require 'lib/weakstorage'
 
-require_relative 'core/utils'
+require_relative '%%RUBY_SITELIBDIR%%/mikutter/core/utils'
 
 require 'boot/check_config_permission'
 require 'boot/mainloop'
