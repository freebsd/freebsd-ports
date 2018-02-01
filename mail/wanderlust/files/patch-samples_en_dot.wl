--- samples/en/dot.wl.orig	2004-11-26 03:59:36 UTC
+++ samples/en/dot.wl
@@ -314,7 +314,7 @@
 
 	;; for Emacs21
 	((and (not (featurep 'xemacs))
-	      (= emacs-major-version 21)
+	      (>= emacs-major-version 21)
 	      (module-installed-p 'x-face-e21))
 	 (autoload 'x-face-decode-message-header "x-face-e21")
 	 (setq wl-highlight-x-face-function 'x-face-decode-message-header))
