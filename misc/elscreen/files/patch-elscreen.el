--- elscreen.el.orig	Wed Sep 19 10:44:10 2001
+++ elscreen.el	Sat Jun 15 15:55:59 2002
@@ -479,7 +479,7 @@
 		      (car (nth j elscreen-mode-to-screen-alist))
 		      elscreen-mode-names)
 		     (progn
-		       (put-alist
+		       (set-alist
 			'elscreen-tmp-name-alist
 			i (cdr (nth j elscreen-mode-to-screen-alist)))
 		       (setq flag nil)))
@@ -590,9 +590,10 @@
   
 
 (defun elscreen-message (message &optional sec)
-  (setq elscreen-last-message message)
-  (message message)
-  (sit-for (or sec 3))
+  (when message
+    (setq elscreen-last-message message)
+    (message "%s" message)
+    (sit-for (or sec 3)))
   (message nil))
 
 ;
