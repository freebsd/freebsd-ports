--- ext/rmmseg/extconf.rb.orig	2014-10-09 14:17:52 UTC
+++ ext/rmmseg/extconf.rb
@@ -1,6 +1,6 @@
 require 'mkmf'
 
-CONFIG['LDSHARED'] = CONFIG['LDSHARED'].sub(/^\$\(CC\)/, 'g++')
+# CONFIG['LDSHARED'] = CONFIG['LDSHARED'].sub(/^\$\(CC\)/, 'g++')
 
 # if RUBY_PLATFORM =~ /darwin/
 # #  CONFIG['LDSHARED'] = 'g++ --dynamiclib -flat_namespace -undefined suppress' 
