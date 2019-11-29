--- lib/puppet/runtime.rb.orig	2019-11-26 01:40:01 UTC
+++ lib/puppet/runtime.rb
@@ -1,4 +1,5 @@
 require 'puppet/http'
+require 'singleton'
 
 class Puppet::Runtime
   include Singleton
