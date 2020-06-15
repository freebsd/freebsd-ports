--- src/init-cl.lisp.orig	2020-06-07 20:30:47 UTC
+++ src/init-cl.lisp
@@ -137,7 +137,8 @@ When one changes, the other does too."
 	  (setq libdir     (combine-path maxima-prefix-env "lib"))
 	  (setq libexecdir (combine-path maxima-prefix-env "libexec"))
 	  (setq datadir    (combine-path maxima-prefix-env "share"))
-	  (setq infodir    (combine-path maxima-prefix-env #+(or cygwin windows win32 win64) "share" "info")))
+	  ;; patch borrowed from SageMath
+	  (setq infodir    (combine-path maxima-prefix-env "share" "info")))
 	(progn
 	  (setq libdir     (maxima-parse-dirstring *autoconf-libdir*))
 	  (setq libexecdir (maxima-parse-dirstring *autoconf-libexecdir*))
