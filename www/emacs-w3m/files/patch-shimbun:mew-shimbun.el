===================================================================
RCS file: /storage/cvsroot/emacs-w3m/shimbun/mew-shimbun.el,v
retrieving revision 1.10.2.9
retrieving revision 1.10.2.10
diff -u -r1.10.2.9 -r1.10.2.10
--- shimbun/mew-shimbun.el	2002/10/31 02:53:17	1.10.2.9
+++ shimbun/mew-shimbun.el	2002/11/04 11:23:54	1.10.2.10
@@ -264,6 +264,12 @@
 		    (format mew-shimbun-lock-format2 group server get count sum))
   (force-mode-line-update))
 
+(w3m-static-if (fboundp 'mew-summary-visit-folder)
+    (defalias 'mew-shimbun-visit-folder 'mew-summary-visit-folder)
+  (defun mew-shimbun-visit-folder (folder)
+    (mew-summary-ls
+     (mew-summary-switch-to-folder folder))))
+
 ;;; Main:
 ;;;###autoload
 (defun mew-shimbun-goto-unseen-folder ()
@@ -381,13 +387,13 @@
 	 (setq dir (mew-expand-folder fld))
 	 (unless (file-directory-p dir)
 	   (mew-make-directory dir))
-	 (mew-summary-visit-folder fld)
+	 (mew-shimbun-visit-folder fld)
 	 (sit-for 0.5)
 	 (mew-rendezvous mew-summary-buffer-process)
 	 (mew-shimbun-retrieve)
 	 (unless (eq (get-buffer cfld) (current-buffer))
 	   (mew-kill-buffer (current-buffer)))))
-     (mew-summary-visit-folder cfld)
+     (mew-shimbun-visit-folder cfld)
      (message "Getting done"))))
 
 (defun mew-shimbun-retrieve-article (mua server group range fld)
@@ -633,13 +639,13 @@
       (when (and (file-directory-p (mew-expand-folder fld))
 		 (file-exists-p (expand-file-name mew-shimbun-db-file
 						  (mew-expand-folder fld))))
-	(mew-summary-visit-folder fld)
+	(mew-shimbun-visit-folder fld)
 	(sit-for 0.5)
 	(mew-rendezvous mew-summary-buffer-process)
 	(mew-shimbun-expire)
 	(unless (eq (get-buffer cfld) (current-buffer))
 	  (mew-kill-buffer (current-buffer)))))
-    (mew-summary-visit-folder cfld)))
+    (mew-shimbun-visit-folder cfld)))
 
 ;;;###autoload
 (defun mew-shimbun-expire ()
