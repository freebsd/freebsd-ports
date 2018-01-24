--- mikutter.rb.orig	2017-12-24 15:00:56 UTC
+++ mikutter.rb
@@ -13,7 +13,7 @@ http://opensource.org/licenses/mit-licen
 =end
 module Mikutter; end
 
-require_relative 'core/boot/option'
+require_relative '%%RUBY_SITELIBDIR%%/mikutter/core/boot/option'
 Mopt.parse exec_command: true
 
 if !ENV['DISABLE_BUNDLER_SETUP'] || ['', '0'].include?(ENV['DISABLE_BUNDLER_SETUP'].to_s)
@@ -33,7 +33,7 @@ require 'webrick'
 require 'thread'
 require 'fileutils'
 
-require_relative 'core/utils'
+require_relative '%%RUBY_SITELIBDIR%%/mikutter/core/utils'
 
 miquire :boot, 'check_config_permission', 'mainloop', 'delayer'
 miquire :core, 'environment'
