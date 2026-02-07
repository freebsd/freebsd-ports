--- lib/specinfra/backend/exec.rb.orig	2016-06-08 01:29:29 UTC
+++ lib/specinfra/backend/exec.rb
@@ -1,7 +1,6 @@
 require 'singleton'
 require 'fileutils'
 require 'shellwords'
-require 'sfl'
 
 module Specinfra
   module Backend
