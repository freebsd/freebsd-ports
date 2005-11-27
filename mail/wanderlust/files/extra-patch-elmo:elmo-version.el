--- elmo/elmo-version.el.orig	Sun Nov 27 22:34:49 2005
+++ elmo/elmo-version.el	Sun Nov 27 22:41:22 2005
@@ -42,6 +42,19 @@
   ;; Don't forget to check `wl-version.el' and Info.
   (product-define "ELMO" nil '(2 14 0)))
 
+(defun product-version-as-string (product)
+  "Return version number of product as a string.
+PRODUCT is a product structure which returned by `product-define'.
+If optional argument UPDATE is non-nil, then regenerate
+`produce-version-string' from `product-version'."
+  (setq product (product-find product))
+  (or (product-version-string product)
+      (and (product-version product)
+           (product-set-version-string product
+                                       (mapconcat (function int-to-string)
+                                                  (product-version product)
+                                                  ".")))))
+
 ;; set version-string
 (product-version-as-string 'elmo-version)
 
