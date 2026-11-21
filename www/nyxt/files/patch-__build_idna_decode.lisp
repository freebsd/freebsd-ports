--- _build/idna/decode.lisp.orig	2026-06-12 10:25:38 UTC
+++ _build/idna/decode.lisp
@@ -81,10 +81,11 @@
 
              ;; case of last character determines uppercase flag:
              (when preserve-case
-               (setf case-flags (nconc (subseq case-flags 0 i)
-                                       (list (< (- (char-code (aref input (1- ic))) 65)
-                                                26))
-                                       (subseq case-flags i))))
+               (setf case-flags (concatenate 'vector
+                                             (subseq case-flags 0 i)
+                                             (list (< (- (char-code (aref input (1- ic))) 65)
+                                                      26))
+                                             (subseq case-flags i))))
 
              (setf output (nconc (subseq output 0 i) (list n) (subseq output i)))
              (incf output-length)
@@ -94,8 +95,8 @@
       (loop with len = output-length
             for i from 0 below len
             do (when (elt case-flags i)
-                 (setf (aref output i)
-                       (char-code (char-upcase (code-char (aref output i))))))))
+                 (setf (elt output i)
+                       (char-code (char-upcase (code-char (elt output i))))))))
     (map 'string #'code-char output)))
 
 (defun to-unicode (string)
