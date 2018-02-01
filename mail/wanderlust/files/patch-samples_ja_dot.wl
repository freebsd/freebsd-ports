--- samples/ja/dot.wl.orig	2004-11-26 03:59:37 UTC
+++ samples/ja/dot.wl
@@ -320,7 +320,7 @@
 
 	;; for Emacs21
 	((and (not (featurep 'xemacs))
-	      (= emacs-major-version 21)
+	      (>= emacs-major-version 21)
 	      (module-installed-p 'x-face-e21))
 	 (autoload 'x-face-decode-message-header "x-face-e21")
 	 (setq wl-highlight-x-face-function 'x-face-decode-message-header))
