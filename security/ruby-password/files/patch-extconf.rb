--- extconf.rb.orig	Wed Jun 19 09:29:52 2002
+++ extconf.rb	Fri Sep 20 04:47:59 2002
@@ -4,34 +4,44 @@
 
 require 'mkmf'
 
-CRACK_DICT = 'cracklib_dict.pwd'
+search_dicts = %w(
+/usr/local/lib/pw_dict.pwd
+/usr/lib/pw_dict.pwd
+/opt/lib/pw_dict.pwd
+/usr/local/lib/cracklib_dict.pwd
+/usr/lib/cracklib_dict.pwd
+/opt/lib/cracklib_dict.pwd
+)
 
-dict = []
-search_dirs = %w(/usr/local /usr /opt)
+if dict = with_config('crack-dict')
+  search_dicts.unshift(dict)
+end
 
-# find the crack dictionary
-print "checking for #{CRACK_DICT}... "
-search_dirs.each do |d|
-  dict = Dir.glob(File.join(d, "lib", CRACK_DICT))
+crack_dict = nil
 
+# find the crack dictionary
+print "checking for cracklib dictionary... "
+search_dicts.each do |dict|
   # create a header file pointing to the crack dictionary
-  unless dict.empty?
-    puts "yes"
-    path = dict[0].sub(/\.pwd/, '')
-    hfile = File.new("rbcrack.h", 'w')
-    hfile.printf("#define CRACK_DICT \"%s\"\n", path)
-    hfile.close
+  if File.exist?(dict)
+    puts dict
+    crack_dict = dict.sub(/\.pwd/, '')
     break
   end
-
 end
 
-if dict.empty?
-  puts "no\nCouldn't find #{CRACK_DICT} on this system"
+if crack_dict.nil?
+  puts "no\nCouldn't find a cracklib dictionary on this system"
   exit 1
 end
 
-have_library('crack', 'FascistCheck')
+hfile = File.new("rbcrack.h", 'w')
+hfile.printf("#define CRACK_DICT \"%s\"\n", crack_dict)
+hfile.close
+
+(have_header('packer.h') || have_header('crack.h')) &&
+  have_library('crack', 'FascistCheck') or exit 1
+
 create_makefile('crack')
 
 File.open('Makefile', 'a') do |f|
