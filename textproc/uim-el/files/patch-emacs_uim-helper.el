--- emacs/uim-helper.el.orig	2017-08-14 00:07:26 UTC
+++ emacs/uim-helper.el
@@ -106,7 +106,7 @@
     (if (not proc)
 	(error "uim.el: Couldn't invoke uim-el-helper-agent."))
 
-    (process-kill-without-query proc)
+    (set-process-query-on-exit-flag proc nil)
 
     ;; wait "OK"
     (let ((patience uim-startup-timeout) (ok nil))
