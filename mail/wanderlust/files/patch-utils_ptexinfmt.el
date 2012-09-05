
$FreeBSD$

--- utils/ptexinfmt.el.orig
+++ utils/ptexinfmt.el
@@ -68,50 +68,50 @@
   "Declare a symbol FACILITY is broken if ASSERTION is nil.
 DOCSTRING will be printed if ASSERTION is nil and
 `ptexinfmt-disable-broken-notice-flag' is nil."
-  (` (let ((facility '(, facility))
-	   (docstring (, docstring))
-	   (assertion (eval '(, assertion))))
+  `(let ((facility ',facility)
+	   (docstring ,docstring)
+	   (assertion (eval ,assertion)))
        (put facility 'broken (not assertion))
        (if assertion
 	   nil
 	 (put facility 'broken-docstring docstring)
 	 (if ptexinfmt-disable-broken-notice-flag
 	     nil
-	   (message "BROKEN FACILITY DETECTED: %s" docstring))))))
+	   (message "BROKEN FACILITY DETECTED: %s" docstring)))))
 
 (put 'ptexinfmt-defun-if-broken 'lisp-indent-function 'defun)
 (defmacro ptexinfmt-defun-if-broken (&rest args)
   "Redefine a function just like `defun' if it is considered broken."
   (let ((name (list 'quote (car args))))
     (setq args (cdr args))
-    (` (prog1
-	   (, name)
-	 (if (get (, name) 'broken)
-	     (defalias (, name)
-	       (function (lambda (,@ args)))))))))
+    `(prog1
+	   ,name
+	 (if (get ,name 'broken)
+	     (defalias ,name
+	       (function (lambda ,@args)))))))
 
 (put 'ptexinfmt-defun-if-void 'lisp-indent-function 'defun)
 (defmacro ptexinfmt-defun-if-void (&rest args)
   "Define a function just like `defun' unless it is already defined."
   (let ((name (list 'quote (car args))))
     (setq args (cdr args))
-    (` (prog1
-	   (, name)
-	 (if (fboundp (, name))
+    `(prog1
+	   ,name
+	 (if (fboundp ,name)
 	     nil
-	   (defalias (, name)
-	     (function (lambda (,@ args)))))))))
+	   (defalias ,name
+	     (function (lambda ,@args)))))))
 
 (put 'ptexinfmt-defvar-if-void 'lisp-indent-function 'defun)
 (defmacro ptexinfmt-defvar-if-void (&rest args)
   "Define a variable just like `defvar' unless it is already defined."
   (let ((name (car args)))
     (setq args (cdr args))
-    (` (prog1
-	   (defvar (, name))
-	 (if (boundp '(, name))
+    `(prog1
+	   (defvar ,name)
+	 (if (boundp ',name)
 	     nil
-	   (defvar (, name) (,@ args)))))))
+	   (defvar ,name ,@args)))))
 
 ;; sort -fd
 (ptexinfmt-broken-facility texinfo-format-printindex
@@ -509,7 +509,7 @@
   (goto-char texinfo-command-start))
 
 ;; @,{c}	==>	c,	cedilla accent
-(put ', 'texinfo-format 'texinfo-format-cedilla-accent)
+(put '\, 'texinfo-format 'texinfo-format-cedilla-accent)
 (ptexinfmt-defun-if-void texinfo-format-cedilla-accent ()
   (insert (texinfo-parse-arg-discard) ",")
   (goto-char texinfo-command-start))
