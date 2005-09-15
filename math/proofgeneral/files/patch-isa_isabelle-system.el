--- isa/isabelle-system.el.orig	Thu Sep  8 12:43:45 2005
+++ isa/isabelle-system.el	Thu Sep  8 12:45:12 2005
@@ -73,10 +73,6 @@
 with full path."
   (interactive)
   (unless (or isatool-not-found (file-executable-p isa-isatool-command))
-    (setq isa-isatool-command
-	  (read-file-name
-	   "Please give the full path to `isatool' (RET if you don't have it): "
-	   nil nil nil))
     (if (not (file-executable-p isa-isatool-command))
 	(progn
 	  (setq isatool-not-found t)
