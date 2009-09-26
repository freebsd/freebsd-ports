--- samples/ja/dot.wl.orig	2009-09-26 19:48:32.000000000 +0900
+++ samples/ja/dot.wl	2009-09-26 19:49:02.000000000 +0900
@@ -320,7 +320,7 @@
 
 	;; for Emacs21
 	((and (not (featurep 'xemacs))
-	      (= emacs-major-version 21)
+	      (>= emacs-major-version 21)
 	      (module-installed-p 'x-face-e21))
 	 (autoload 'x-face-decode-message-header "x-face-e21")
 	 (setq wl-highlight-x-face-function 'x-face-decode-message-header))
