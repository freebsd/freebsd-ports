--- lisp/tramp-util.el.orig	Sun Dec 30 06:56:58 2001
+++ lisp/tramp-util.el	Tue Mar 26 23:12:09 2002
@@ -27,6 +27,7 @@
 
 ;;; Code:
 
+(eval-when-compile (require 'cl))
 (require 'compile)
 (require 'tramp)
 
