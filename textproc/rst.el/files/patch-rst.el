--- rst.el.orig	Sun Aug 20 18:19:59 2006
+++ rst.el	Sun Aug 20 17:41:37 2006
@@ -930,7 +930,9 @@
          (toggle-style
           (and current-prefix-arg (not reverse-direction))))
 
-    (if (and transient-mark-mode mark-active)
+    (if (or
+	 (and (fboundp 'region-active-p) (region-active-p) (region-exists-p))
+	 (and (boundp 'transient-mark-mode) transient-mark-mode mark-active))
         ;; Adjust decorations within region.
         (rst-promote-region current-prefix-arg)
       ;; Adjust decoration around point.
@@ -1988,7 +1990,11 @@
     (error "Cannot mark zero sections"))
   (cond ((and allow-extend
 	      (or (and (eq last-command this-command) (mark t))
-		  (and transient-mark-mode mark-active)))
+		  (or
+		   (and (fboundp 'region-active-p)
+			(region-active-p) (region-exists-p))
+		   (and (boundp 'transient-mark-mode)
+			transient-mark-mode mark-active))))
 	 (set-mark
 	  (save-excursion
 	    (goto-char (mark))
