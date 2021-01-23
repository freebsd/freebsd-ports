--- lisp/ess-r-package.el.orig	2021-01-22 20:38:19 UTC
+++ lisp/ess-r-package.el
@@ -557,7 +557,7 @@ package mode. Use this function if state of the buffer
   (error "As of ESS 16.04, `ess-developer' is deprecated. Use `ess-r-set-evaluation-env' instead"))
 
 (defalias 'ess-toggle-developer 'ess-developer)
-(define-obsolete-function-alias 'ess-r-devtools-check-package-buildwin 'ess-r-devtools-check-with-winbuilder)
+(define-obsolete-function-alias 'ess-r-devtools-check-package-buildwin 'ess-r-devtools-check-with-winbuilder "18.04")
 (define-obsolete-function-alias 'ess-r-devtools-ask 'ess-r-devtools-execute-command "18.04")
 
 (make-obsolete-variable 'ess-developer "Please use `ess-developer-select-package' and `ess-r-set-evaluation-env' instead." "16.04")
