--- ext/extconf.rb.orig	2017-01-04 01:13:32 UTC
+++ ext/extconf.rb
@@ -4,8 +4,8 @@ RbConfig::MAKEFILE_CONFIG['CC'] = ENV['C
 extension_name = 'krb5_auth'
 dir_config(extension_name)
 have_library("c", "main")
-raise "Cannot find krb5 library" unless have_library("krb5","krb5_init_context")
-raise "Cannot find krb5 headers" unless have_header("krb5.h")
-have_library("com_err","error_message")
-have_header("com_err.h")
+raise "Cannot find krb5 library" unless find_library("krb5","krb5_init_context")
+raise "Cannot find krb5 headers" unless find_header("krb5.h")
+find_library("com_err","error_message")
+find_header("com_err.h")
 create_makefile('krb5_auth')
