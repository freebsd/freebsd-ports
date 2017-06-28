--- ruby/lib/gitaly.rb.orig	2017-06-22 08:27:11 UTC
+++ ruby/lib/gitaly.rb
@@ -1,7 +1,6 @@
 $:.unshift(File.expand_path('../gitaly', __FILE__))
 
 require "gitaly/version"
-require "gitaly/gitaly_services_pb"
 
 module Gitaly
   # Your code goes here...
