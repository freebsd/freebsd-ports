--- src/grind.lisp.orig	2019-10-21 03:38:59 UTC
+++ src/grind.lisp
@@ -297,12 +297,13 @@
       (msz nil l r)
       (do ((nl) (w 0))
           ((null (cdr x))
-           (setq nl (cons (if (stringp (car x))
+;; Patch borrowed from SageMath: undoing_true_false_printing_patch
+           (setq nl (cons (if (atom (car x))
                               (msz (makestring (car x)) l r)
                               (msize (car x) l r lop rop))
                           nl))
            (cons (+ w (caar nl)) (nreverse nl)))
-        (setq nl (cons (if (stringp (car x))
+        (setq nl (cons (if (atom (car x))
                            (msz (makestring (car x)) l r)
                            (msize (car x) l r lop rop))
                        nl)
