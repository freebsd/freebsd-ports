--- isa/isabelle-system.el.orig	Thu Dec  8 07:43:17 2005
+++ isa/isabelle-system.el	Thu Dec  8 07:43:38 2005
@@ -74,10 +74,6 @@
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
