--- mu4e/mu4e-utils.el.orig	2021-01-23 02:05:25 UTC
+++ mu4e/mu4e-utils.el
@@ -1073,7 +1073,7 @@ in the background; otherwise, pop up a window."
       (kill-process proc t))))
 
 (define-obsolete-function-alias 'mu4e-interrupt-update-mail
-  'mu4e-kill-update-mail)
+  'mu4e-kill-update-mail "1.0-alpha0")
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 
 
