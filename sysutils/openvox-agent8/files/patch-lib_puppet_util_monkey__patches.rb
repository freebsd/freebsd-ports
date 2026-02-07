--- lib/puppet/util/monkey_patches.rb.orig	2025-12-22 21:26:30 UTC
+++ lib/puppet/util/monkey_patches.rb
@@ -52,12 +52,6 @@ unless Puppet::Util::Platform.jruby_fips?
 require_relative '../../puppet/ssl/openssl_loader'
 unless Puppet::Util::Platform.jruby_fips?
   class OpenSSL::SSL::SSLContext
-    if DEFAULT_PARAMS[:options]
-      DEFAULT_PARAMS[:options] |= OpenSSL::SSL::OP_NO_SSLv3
-    else
-      DEFAULT_PARAMS[:options] = OpenSSL::SSL::OP_NO_SSLv3
-    end
-
     alias __original_initialize initialize
     private :__original_initialize
 
