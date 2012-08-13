
$FreeBSD$

--- tuareg.el.orig
+++ tuareg.el
@@ -1245,8 +1245,7 @@
 possible."
  (if (eq major-mode 'tuareg-mode)
      (let ((beg nil) (end nil))
-       (save-excursion
-	 (set-buffer compilation-last-buffer)
+       (with-current-buffer compilation-last-buffer
 	 (save-excursion
 	   (goto-char (window-point (get-buffer-window (current-buffer) t)))
 	   (if (looking-at tuareg-error-chars-regexp)
@@ -1438,11 +1437,11 @@
 (defun tuareg-find-match ()
   (tuareg-find-kwop tuareg-find-kwop-regexp))
 
-(defconst tuareg-find-,-match-regexp
+(defconst tuareg-find-comma-match-regexp
   (tuareg-make-find-kwop-regexp
    "\\<\\(and\\|match\\|begin\\|else\\|exception\\|then\\|try\\|with\\|or\\|fun\\|function\\|let\\|do\\)\\>\\|->\\|[[{(]"))
-(defun tuareg-find-,-match ()
-  (tuareg-find-kwop tuareg-find-,-match-regexp))
+(defun tuareg-find-comma-match ()
+  (tuareg-find-kwop tuareg-find-comma-match-regexp))
 
 (defconst tuareg-find-with-match-regexp
   (tuareg-make-find-kwop-regexp
@@ -1922,7 +1921,7 @@
 		  ((string= kwop ",")
 		   (if (looking-at ",[ \t]*\\((\\*\\|$\\)")
 		       (progn
-			 (setq kwop (tuareg-find-,-match))
+			 (setq kwop (tuareg-find-comma-match))
 			 (if (or (looking-at "[[{(]\\|\\.<")
 				 (and (looking-at "[<|]")
 				      (char-equal ?\[ (preceding-char))
