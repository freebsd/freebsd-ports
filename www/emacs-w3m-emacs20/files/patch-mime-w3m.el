--- mime-w3m.el.orig	Thu Mar 15 04:58:36 2001
+++ mime-w3m.el	Thu Mar 15 04:58:43 2001
@@ -64,7 +64,6 @@
     (cons 'progn body)))
 
 (defun mime-w3m-preview-text/html (entity situation)
-  (setq mime-w3m-message-structure (mime-find-root-entity entity))
   (let ((p (point))
 	(xref (mime-entity-fetch-field entity "xref")))
     ;; For nnshimbun.el.
