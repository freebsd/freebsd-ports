--- common/dbl1de.dsl.orig	Thu Oct 26 14:33:11 2000
+++ common/dbl1de.dsl	Fri Jan 19 09:36:46 2001
@@ -278,7 +278,7 @@
    (list (normalize "abstract")		": ")
    (list (normalize "answer")		" ")
    (list (normalize "appendix")		". ")
-   (list (normalize "caution")		"")
+   (list (normalize "caution")		": ")
    (list (normalize "chapter")		". ")
    (list (normalize "equation")		". ")
    (list (normalize "example")		". ")
@@ -310,7 +310,7 @@
    (list (normalize "step")		". ")
    (list (normalize "table")		". ")
    (list (normalize "tip")		": ")
-   (list (normalize "warning")		"")
+   (list (normalize "warning")		": ")
    ))
 
 (define (gentext-de-label-title-sep gind)
@@ -372,9 +372,9 @@
 	       (err (node-list-error msg (current-node))))
 	  msg))))
 
-(define %gentext-de-start-quote% "\U-201E;")
+(define %gentext-de-start-quote% (dingbat "ldquo"))
 
-(define %gentext-de-end-quote% "\U-201C;")
+(define %gentext-de-end-quote% (dingbat "rdquo"))
 
 (define %gentext-de-start-nested-quote% "\U-201A;")
 
