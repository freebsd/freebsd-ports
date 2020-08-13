--- emacs/uim.el.orig	2018-05-08 04:53:27 UTC
+++ emacs/uim.el
@@ -488,7 +488,7 @@
 	(error "uim.el: Couldn't invoke uim-el-agent."))
     
     ;; don't ask kill
-    (process-kill-without-query proc)
+    (set-process-query-on-exit-flag proc nil)
 
     ;; wait "OK"
     (let ((patience uim-startup-timeout) (ok nil))
