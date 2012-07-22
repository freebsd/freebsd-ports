--- lib/quickml/utils.rb.orig	2004-06-07 17:50:59.000000000 +0900
+++ lib/quickml/utils.rb	2012-06-21 16:06:07.000000000 +0900
@@ -1,3 +1,4 @@
+#coding: euc-jp
 #
 # quickml/utils - a part of quickml server
 #
@@ -8,10 +9,9 @@
 # You can redistribute it and/or modify it under the terms of 
 # the GNU General Public License version 2.
 #
-$KCODE = 'e'
 require 'kconv'
 require 'net/smtp'
-require 'ftools'
+require 'fileutils'
 
 class TooLongLine < Exception; end
 class IO
