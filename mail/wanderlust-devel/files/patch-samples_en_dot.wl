--- samples/en/dot.wl.orig	2009-09-26 19:47:36.000000000 +0900
+++ samples/en/dot.wl	2009-09-26 19:47:42.000000000 +0900
@@ -314,7 +314,7 @@
 
 	;; for Emacs21
 	((and (not (featurep 'xemacs))
-	      (= emacs-major-version 21)
+	      (>= emacs-major-version 21)
 	      (module-installed-p 'x-face-e21))
 	 (autoload 'x-face-decode-message-header "x-face-e21")
 	 (setq wl-highlight-x-face-function 'x-face-decode-message-header))
