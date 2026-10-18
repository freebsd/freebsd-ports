--- build/common_library.rb.orig	2013-10-27 00:00:00 UTC
+++ build/common_library.rb
@@ -166,13 +166,13 @@ else
   LIBEV_TARGET = nil
 
   let(:libev_cflags) do
-    result = string_option('LIBEV_CFLAGS', '-I/usr/include/libev')
+    result = string_option('LIBEV_CFLAGS', '')
     # Apple Clang 4.2 complains about ambiguous member templates in ev++.h.
     result += ' -Wno-ambiguous-member-template' if PlatformInfo.compiler_supports_wno_ambiguous_member_template?
     result
   end
 
-  let(:libev_libs) { string_option('LIBEV_LIBS', '-lev') }
+  let(:libev_libs) { string_option('LIBEV_LIBS', '') }
 
   task :libev  # do nothing
 end
