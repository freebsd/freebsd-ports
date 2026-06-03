--- _build/cl-webkit/webkit2/webkit2.web-view.lisp.orig	2025-11-09 06:31:52 UTC
+++ _build/cl-webkit/webkit2/webkit2.web-view.lisp
@@ -276,7 +276,8 @@
 
 (declaim (ftype (function (webkit-web-view string &optional
                                            (or null (function (t t)))
-                                           (or null (function (condition))) string))
+                                           (or null (function (condition)))
+                                           (or null string)))
                 webkit-web-view-evaluate-javascript))
 (defun webkit-web-view-evaluate-javascript (web-view javascript
                                             &optional call-back error-call-back world)
