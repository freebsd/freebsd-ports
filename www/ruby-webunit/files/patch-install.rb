--- install.rb.orig	Thu Jul 26 17:50:49 2001
+++ install.rb	Thu Sep 20 14:59:29 2001
@@ -5,7 +5,7 @@
 =end
 
 require 'rbconfig'
-lib_dir = Config::CONFIG['sitedir']
+lib_dir = File.join(Config::CONFIG['sitedir'], Config::CONFIG['ruby_version'])
 bin_dir = Config::CONFIG['bindir']
 
 require 'ftools'
@@ -23,7 +23,7 @@
   File::install( path, to, 0644, true )
 }
 
-%w( html-parser  htmlrepair ).each do |dir|
+%w(  ).each do |dir|
   Dir::chdir( BASEDIR + '/contrib/' + dir )
   system( 'ruby install.rb' )
 end
