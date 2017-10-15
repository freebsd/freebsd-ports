--- mikutter.rb.orig	2017-10-08 12:29:16 UTC
+++ mikutter.rb
@@ -11,7 +11,7 @@ This software is released under the MIT 
 http://opensource.org/licenses/mit-license.php
 
 =end
-require_relative 'core/boot/option'
+require_relative '%%RUBY_SITELIBDIR%%/mikutter/core/boot/option'
 Mopt.parse exec_command: true
 
 if !ENV['DISABLE_BUNDLER_SETUP'] || ['', '0'].include?(ENV['DISABLE_BUNDLER_SETUP'].to_s)
@@ -31,7 +31,7 @@ require 'webrick'
 require 'thread'
 require 'fileutils'
 
-require_relative 'core/utils'
+require_relative '%%RUBY_SITELIBDIR%%/mikutter/core/utils'
 
 miquire :boot, 'check_config_permission', 'mainloop', 'delayer'
 miquire :core, 'service', 'environment'
