--- lib/mcollective/monkey_patches.rb.orig	2026-06-03 23:37:51 UTC
+++ lib/mcollective/monkey_patches.rb
@@ -130,30 +130,3 @@ end
     end
   end
 end
-
-# Reject all SSLv2 ciphers and all SSLv2 or SSLv3 handshakes by default
-require "openssl"
-class OpenSSL::SSL::SSLContext # rubocop:disable Style/ClassAndModuleChildren
-  if DEFAULT_PARAMS[:options]
-    DEFAULT_PARAMS[:options] |= OpenSSL::SSL::OP_NO_SSLv2 | OpenSSL::SSL::OP_NO_SSLv3
-  else
-    DEFAULT_PARAMS[:options] = OpenSSL::SSL::OP_NO_SSLv2 | OpenSSL::SSL::OP_NO_SSLv3
-  end
-
-  # ruby 1.8.5 doesn't define this constant, but has it on by default
-  DEFAULT_PARAMS[:options] |= OpenSSL::SSL::OP_DONT_INSERT_EMPTY_FRAGMENTS if defined?(OpenSSL::SSL::OP_DONT_INSERT_EMPTY_FRAGMENTS)
-
-  DEFAULT_PARAMS[:ciphers] << ":!SSLv2" if DEFAULT_PARAMS[:ciphers]
-
-  alias __mcollective_original_initialize initialize
-  private :__mcollective_original_initialize
-
-  def initialize(*args)
-    __mcollective_original_initialize(*args)
-    params = {
-      :options => DEFAULT_PARAMS[:options],
-      :ciphers => DEFAULT_PARAMS[:ciphers]
-    }
-    set_params(params)
-  end
-end
