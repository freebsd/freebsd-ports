--- lisp/tramp.el.orig	Sat Sep 23 19:12:34 2006
+++ lisp/tramp.el	Sat Sep 23 19:13:19 2006
@@ -5922,8 +5922,8 @@
   "Return the right method string to use.
 This is METHOD, if non-nil. Otherwise, do a lookup in
 `tramp-default-method-alist'."
-  (if (tramp-completion-mode)
-      method
+;  (if (tramp-completion-mode)
+;      method
     (or method
 	(let ((choices tramp-default-method-alist)
 	      lmethod item)
@@ -5934,7 +5934,7 @@
 	      (setq lmethod (nth 2 item))
 	      (setq choices nil)))
 	  lmethod)
-	tramp-default-method)))
+	tramp-default-method));)
 
 (defsubst tramp-find-user (method user host)
   "Return the right user string to use.
