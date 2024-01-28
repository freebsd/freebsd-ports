--- emacs/uim-leim.el.orig	2024-01-27 11:04:16 UTC
+++ emacs/uim-leim.el
@@ -62,7 +62,7 @@
 
   (let (im)
     ;; register inactivation function
-    (setq inactivate-current-input-method-function 'uim-leim-inactivate)
+    (setq deactivate-current-input-method-function 'uim-leim-inactivate)
 
     ;; get plain IM engine name from LEIM style name
     ;;  ex. "Japanese-anthy-uim" => "anthy"
@@ -80,7 +80,7 @@
 (defun uim-leim-reset ()
   (when uim-leim-active
     (message "uim.el: uim-leim-reset")
-    (inactivate-input-method)))
+    (deactivate-input-method)))
 
 
 (defun uim-leim-make-im-name (im)
@@ -156,12 +156,12 @@
 	    (lambda ()
 	      (when uim-leim-active
 		(message "uim.el: LEIM inactivated"
-			 (inactivate-input-method)))))
+			 (deactivate-input-method)))))
 
   (add-hook 'uim-buffer-init-hook 
 	    (lambda ()
 	      (add-hook 'change-major-mode-hook
-			'inactivate-input-method nil t)))
+			'deactivate-input-method nil t)))
 
   ;; 
   ;;uim-leim-update-label 
