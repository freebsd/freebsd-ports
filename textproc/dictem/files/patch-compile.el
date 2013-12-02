--- /dev/null	2013-11-20 22:00:00.000000000 +0300
+++ compile.el	2013-11-20 21:34:57.112822385 +0300
@@ -0,0 +1,13 @@
+;; -*- emacs-lisp -*-
+
+;;
+;; Help ports system compile for emacs and xemacs
+;;
+
+(require 'bytecomp)
+
+(add-to-list 'load-path (expand-file-name "."))
+
+(defun compile-dictem ()
+  (mapcar 'byte-compile-file command-line-args-left))
+
