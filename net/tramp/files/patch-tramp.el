Index: lisp/tramp.el
===================================================================
RCS file: /cvsroot/tramp/tramp/lisp/tramp.el,v
retrieving revision 2.359.2.3
retrieving revision 2.359.2.4
diff -u -r2.359.2.3 -r2.359.2.4
--- lisp/tramp.el	29 May 2004 21:40:49 -0000	2.359.2.3
+++ lisp/tramp.el	30 May 2004 20:55:59 -0000	2.359.2.4
@@ -1885,6 +1885,16 @@
 ;; To be activated for debugging containing this macro
 (def-edebug-spec with-parsed-tramp-file-name t)
 
+(defmacro tramp-let-maybe (variable value &rest body)
+  "Let-bind VARIABLE to VALUE in BODY, but only if VARIABLE is not obsolete.
+BODY is executed whether or not the variable is obsolete.
+The intent is to protect against `obsolete variable' warnings."
+  `(if (get ',variable 'byte-obsolete-variable)
+       (progn ,@body)
+     (let ((,variable ,value))
+       ,@body)))
+(put 'tramp-let-maybe 'lisp-indent-function 2)
+
 ;;; Config Manipulation Functions:
 
 (defun tramp-set-completion-function (method function-list)
@@ -6790,16 +6800,6 @@
     (funcall (symbol-function 'process-kill-without-query)
 	     process flag)))
 
-(defmacro tramp-let-maybe (variable value &rest body)
-  "Let-bind VARIABLE to VALUE in BODY, but only if VARIABLE is not obsolete.
-BODY is executed whether or not the variable is obsolete.
-The intent is to protect against `obsolete variable' warnings."
-  `(if (get 'byte-obsolete-variable ',variable)
-       (progn ,@body)
-     (let ((,variable ,value))
-       ,@body)))
-(put 'tramp-let-maybe 'lisp-indent-function 2)
-
 
 ;; ------------------------------------------------------------ 
 ;; -- Kludges section -- 
