--- common/dbl1de.dsl.orig	Thu Oct 26 14:33:11 2000
+++ common/dbl1de.dsl	Sat Jan  6 13:30:03 2001
@@ -372,9 +372,9 @@
 	       (err (node-list-error msg (current-node))))
 	  msg))))
 
-(define %gentext-de-start-quote% "\U-201E;")
+(define %gentext-de-start-quote% (dingbat "ldquo"))
 
-(define %gentext-de-end-quote% "\U-201C;")
+(define %gentext-de-end-quote% (dingbat "rdquo"))
 
 (define %gentext-de-start-nested-quote% "\U-201A;")
 
