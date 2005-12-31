--- w3mhack.el.orig	Sat Dec 31 22:56:04 2005
+++ w3mhack.el	Sat Dec 31 22:56:43 2005
@@ -1180,7 +1180,7 @@
 		     `(lambda (&rest args)
 			(apply ,si:push-mark (car args) t (cddr args)))))
 	      (unwind-protect
-		  (texinfo-format-buffer nil)
+		  (texinfo-format-buffer t)
 		(fset 'message si:message)
 		(fset 'push-mark si:push-mark)))
 	    (if (buffer-modified-p)
