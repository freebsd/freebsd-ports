--- ext/nokogumboc/extconf.rb.orig	2015-07-26 21:04:54 UTC
+++ ext/nokogumboc/extconf.rb
@@ -1,3 +1,4 @@
+require 'rubygems'
 require 'mkmf'
 $CFLAGS += " -std=c99"
 
@@ -10,7 +11,7 @@ if have_library('xml2', 'xmlNewDoc')
     select { |name| name.match(%r{gems/nokogiri-([\d.]+)/lib/nokogiri}) }.
     sort_by {|name| name[/nokogiri-([\d.]+)/,1].split('.').map(&:to_i)}.last
   if nokogiri_lib
-    nokogiri_ext = nokogiri_lib.sub(%r(lib/nokogiri(.rb)?$), 'ext/nokogiri')
+    nokogiri_ext = Gem::Specification.find_by_name('nokogiri').extension_dir + "/nokogiri"
 
     # if that doesn't work, try workarounds found in Nokogiri's extconf
     unless find_header('nokogiri.h', nokogiri_ext)
