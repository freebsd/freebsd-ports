--- dictionary.el.orig	2004-10-02 06:31:20 UTC
+++ dictionary.el
@@ -330,7 +330,8 @@ by the choice value:
   (make-local-variable 'dictionary-default-dictionary)
   (make-local-variable 'dictionary-default-strategy)
   
-  (make-local-hook 'kill-buffer-hook)
+  (if (fboundp 'make-local-hook)
+      (make-local-hook 'kill-buffer-hook))
   (add-hook 'kill-buffer-hook 'dictionary-close t t)
   (run-hooks 'dictionary-mode-hook))
 
