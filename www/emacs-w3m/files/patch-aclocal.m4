--- aclocal.m4.orig	2018-01-16 09:35:31 UTC
+++ aclocal.m4
@@ -78,15 +78,18 @@ AC_DEFUN(AC_PATH_EMACS,
 
   AC_MSG_CHECKING([what a flavor does ${EMACS} have])
   AC_EMACS_LISP(flavor,
-    (if (featurep (quote xemacs))
-	\"XEmacs\"
-      (concat \"Emacs \"
-	      (mapconcat (function identity)
-			 (nreverse
-			  (cdr (nreverse
-				(split-string emacs-version
-					      (concat (vector 92 46))))))
-			 \".\"))),
+    (cond ((featurep (quote xemacs))
+	   \"XEmacs\")
+	  ((= (length (split-string emacs-version (concat (vector 92 46)))) 2)
+	   (concat \"Emacs \" emacs-version))
+	  (t
+	   (concat \"Emacs \"
+		   (mapconcat (function identity)
+			      (nreverse
+			       (cdr (nreverse
+				     (split-string emacs-version
+						   (concat (vector 92 46))))))
+			      \".\")))),
     noecho)
   case "${flavor}" in
   XEmacs)
