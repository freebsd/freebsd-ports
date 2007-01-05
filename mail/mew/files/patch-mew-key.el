--- mew-key.el.orig	Wed Jul 12 18:22:49 2006
+++ mew-key.el	Thu Jan  4 20:14:11 2007
@@ -609,13 +609,16 @@
 ;;;
 
 (defun mew-which-mew-etc ()
-  (let ((file "mew.el")
-	(path load-path))
+  (let ((file1 "mew.el")
+        (file2 "Mew.png")
+	(path (list "%%MEWICONDIR%%" load-path)))
     (catch 'loop
       (while path
-	(if (file-exists-p (expand-file-name file (car path)))
+	(if (file-exists-p (expand-file-name file1 (car path)))
 	    (throw 'loop (expand-file-name "etc" (car path)))
-	  (setq path (cdr path)))))))
+        (if (file-exists-p (expand-file-name file2 (car path)))
+	    (throw 'loop (expand-file-name (car path)))
+	  (setq path (cdr path))))))))
 
 (defvar mew-icon-directory (mew-which-mew-etc))
 
