--- lib/tdiary/io/plugin_pstore.rb.orig	2016-01-16 10:18:36 UTC
+++ lib/tdiary/io/plugin_pstore.rb
@@ -4,6 +4,7 @@
 # 	default plugin storage implemented by PStore
 #
 require 'pstore'
+require 'pathname'
 
 module TDiary
 	module IO
