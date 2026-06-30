--- _build/idna/decode.lisp.orig	2026-06-12 10:25:38 UTC
+++ _build/idna/decode.lisp
@@ -94,8 +94,8 @@
       (loop with len = output-length
             for i from 0 below len
             do (when (elt case-flags i)
-                 (setf (aref output i)
-                       (char-code (char-upcase (code-char (aref output i))))))))
+                 (setf (elt output i)
+                       (char-code (char-upcase (code-char (elt output i))))))))
     (map 'string #'code-char output)))
 
 (defun to-unicode (string)
