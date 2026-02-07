--- lib/puppet/util/monkey_patches.rb.orig	2025-12-27 20:44:22 UTC
+++ lib/puppet/util/monkey_patches.rb
@@ -1,6 +1,6 @@
 # frozen_string_literal: true
 
-require_relative '../../puppet/util/platform'
+require_relative "../../puppet/util/platform"
 
 module Puppet::Util::MonkeyPatches
 end
@@ -49,23 +49,17 @@ end
   end
 end
 
-require_relative '../../puppet/ssl/openssl_loader'
+require_relative "../../puppet/ssl/openssl_loader"
 unless Puppet::Util::Platform.jruby_fips?
   class OpenSSL::SSL::SSLContext
-    if DEFAULT_PARAMS[:options]
-      DEFAULT_PARAMS[:options] |= OpenSSL::SSL::OP_NO_SSLv3
-    else
-      DEFAULT_PARAMS[:options] = OpenSSL::SSL::OP_NO_SSLv3
-    end
-
-    alias __original_initialize initialize
+    alias_method :__original_initialize, :initialize
     private :__original_initialize
 
     def initialize(*args)
       __original_initialize(*args)
       params = {
-        :options => DEFAULT_PARAMS[:options],
-        :ciphers => DEFAULT_PARAMS[:ciphers],
+        options: DEFAULT_PARAMS[:options],
+        ciphers: DEFAULT_PARAMS[:ciphers]
       }
       set_params(params)
     end
@@ -75,7 +69,7 @@ if Puppet::Util::Platform.windows?
 if Puppet::Util::Platform.windows?
   class OpenSSL::X509::Store
     @puppet_certs_loaded = false
-    alias __original_set_default_paths set_default_paths
+    alias_method :__original_set_default_paths, :set_default_paths
     def set_default_paths
       # This can be removed once openssl integrates with windows
       # cert store, see https://rt.openssl.org/Ticket/Display.html?id=2158
