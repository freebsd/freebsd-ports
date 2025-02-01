--- source/start.lisp.orig	2025-01-16 09:15:11 UTC
+++ source/start.lisp
@@ -434,6 +434,7 @@ - Start the browser with increased verbosity, a differ
  (asdf:load-system :nyxt/gi-gtk)
  (nyxt:ffi-initialize nyxt:*browser* '() (time:now)))
 "))
+  (sb-int:set-floating-point-modes :traps nil)
   (pushnew 'nyxt-source-registry asdf:*default-source-registries*)
   (asdf:clear-configuration)
   (let ((source-directory (files:expand *source-directory*)))
