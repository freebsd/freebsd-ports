--- lisp/ess-site.el.orig	2026-05-26 14:29:02 UTC
+++ lisp/ess-site.el
@@ -57,7 +57,7 @@
 (require 'essd-els) ;; ess-remote
 (require 'ess-sas-d)
 (require 'ess-bugs-d)
-(require 'ess-jags-d)
+;;(require 'ess-jags-d) ; -> in ./obsolete/ since 2026-03-23, commit c3960e0
 (require 'ess-toolbar)
 
 (provide 'ess-site)
