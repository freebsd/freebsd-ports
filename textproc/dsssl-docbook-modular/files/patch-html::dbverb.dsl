--- html/dbverb.dsl.orig	Sat Mar 15 18:03:51 2003
+++ html/dbverb.dsl	Sat Mar 15 18:05:09 2003
@@ -98,36 +98,9 @@
 	  (para-check 'restart)))))
 
 (define ($verbatim-line-by-line$ indent line-numbers?)
-  (let ((expanded-content
-	 ;; this is the content with
-	 ;; inlinemediaobject/imageobject[@format='linespecific']
-	 ;; expanded
-	 (let loop ((kl (children (current-node))) (rl (empty-node-list)))
-	   (if (node-list-empty? kl)
-	       rl
-	       (if (equal? (gi (node-list-first kl))
-			   (normalize "inlinemediaobject"))
-		   (let* ((imgobj (node-list-filter-by-gi
-				   (children (node-list-first kl))
-				   (list (normalize "imageobject"))))
-			  (datobj (node-list-filter-by-gi
-				   (children imgobj)
-				   (list (normalize "imagedata")))))
-		     (if (and (not (node-list-empty? imgobj))
-			      (not (node-list-empty? datobj))
-			      (equal? (attribute-string (normalize "format") datobj)
-				      (normalize "linespecific")))
-			 (loop (node-list-rest kl)
-			       (node-list rl (string->nodes (include-characters
-							     (if (attribute-string (normalize "fileref") datobj)
-								 (attribute-string (normalize "fileref") datobj)
-								 (entity-generated-system-id (attribute-string (normalize "entityref") datobj)))))))
-			 (loop (node-list-rest kl)
-			       (node-list rl (node-list-first kl)))))
-		   (loop (node-list-rest kl) (node-list rl (node-list-first kl))))))))
     (make sequence
       ($line-start$ indent line-numbers? 1)
-      (let loop ((kl expanded-content)
+      (let loop ((kl (children (current-node)))
 		 (linecount 1)
 		 (res (empty-sosofo)))
 	(if (node-list-empty? kl)
@@ -146,7 +119,7 @@
 				  ($line-start$ indent 
 						line-numbers?
 						(+ linecount 1)))
-		   (sosofo-append res (process-node-list c))))))))))
+		   (sosofo-append res (process-node-list c)))))))))
 
 (define ($linespecific-display$ indent line-numbers?)
   (make element gi: "P"
