--- src/hayat.lisp.orig	2020-05-21 06:20:25 UTC
+++ src/hayat.lisp
@@ -2205,6 +2205,25 @@
       (or (alike1 (exp-pt (get-datum (datum-var (car l)))) (exp-pt (car l)))
 	  (return () ))))
 
+;; Patch borrowed from SageMath: 0001-taylor2-Avoid-blowing-the-stack-when-diff-expand-isn
+;;
+;; SUBTREE-SEARCH
+;;
+;; Search for subtrees, ST, of TREE that contain an element equal to BRANCH
+;; under TEST as an immediate child and return them as a list.
+;;
+;; Examples:
+;;   (SUBTREE-SEARCH 2 '(1 2 3)) => '((1 2 3))
+;;   (SUBTREE-SEARCH 2 '(1 2 2 3)) => '((1 2 2 3))
+;;   (SUBTREE-SEARCH 2 '(1 (2) 3)) => '((2))
+;;   (SUBTREE-SEARCH 4 '(1 (2) 3)) => NIL
+;;   (SUBTREE-SEARCH 2 '(1 (2) 3 (2))) => '((2) (2))
+
+(defun subtree-search (branch tree &optional (test 'equalp))
+  (unless (atom tree)
+    (if (find branch tree :test test) (list tree)
+        (mapcan (lambda (child) (subtree-search branch child test)) tree))))
+
 (defun taylor2  (e)
  (let ((last-exp e))	    ;; lexp-non0 should be bound here when needed
   (cond ((assolike e tlist) (var-expand e 1 () ))
@@ -3032,7 +3051,21 @@
        (and (or (member '$inf pt-list :test #'eq) (member '$minf pt-list :test #'eq))
 	    (unfam-sing-err)))
 
-(defun diff-expand (exp l)		;l is tlist
+;; DIFF-EXPAND
+;;
+;; Expand EXP in the variables as specified in L, which is a list of tlists. If
+;; L is a singleton, this just works by the classic Taylor expansion:
+;;
+;;    f(x) = f(c) + f'(c) + f''(c)/2 + ... + f^(k)(c)/k!
+;;
+;; If L specifies multiple expansions, DIFF-EXPAND works recursively by
+;; expanding one variable at a time. The derivatives are computed using SDIFF.
+;;
+;; In some cases, f'(c) or some higher derivative might be an expression of the
+;; form 1/0. Instead of returning an error, DIFF-EXPAND uses f'(x)
+;; instead. (Note: This seems bogus to me (RJS), but I'm just describing how
+;; EVAL-DERIV works)
+(defun diff-expand (exp l)
   (check-inf-sing (mapcar (function caddr) l))
   (cond ((not l) exp)
 	(t
