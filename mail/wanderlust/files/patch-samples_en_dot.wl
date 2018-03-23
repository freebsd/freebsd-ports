--- samples/en/dot.wl.orig	2017-06-28 06:06:07 UTC
+++ samples/en/dot.wl
@@ -327,7 +327,7 @@
 
 	;; for Emacs21
 	((and (not (featurep 'xemacs))
-	      (= emacs-major-version 21)
+	      (>= emacs-major-version 21)
 	      (module-installed-p 'x-face-e21))
 	 (autoload 'x-face-decode-message-header "x-face-e21")
 	 (setq wl-highlight-x-face-function 'x-face-decode-message-header))
