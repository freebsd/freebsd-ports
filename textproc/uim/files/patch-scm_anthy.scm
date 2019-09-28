--- scm/anthy.scm.orig	2017-08-14 00:07:27 UTC
+++ scm/anthy.scm
@@ -67,6 +67,10 @@
 (define anthy-candidate-type-upper-halfwidth-alnum -7)
 (define anthy-candidate-type-upper-fullwidth-alnum -8)
 
+(define anthy-compiled-encoding 0)
+(define anthy-euc-jp-encoding 1)
+(define anthy-utf8-encoding 2)
+
 ;; I don't think the key needs to be customizable.
 (define-key anthy-space-key? '(" "))
 
@@ -85,12 +89,12 @@
      ((anthy-context-converting ac)
       (anthy-do-commit ac))
      ((anthy-context-transposing ac)
-      (im-commit ac (anthy-transposing-text ac)))
+      (im-commit ac (anthy-lib-eucjp-to-utf8 (anthy-transposing-text ac))))
      ((and
        (anthy-context-on ac)
        (anthy-has-preedit? ac))
       (im-commit
-       ac (anthy-make-whole-string ac #t (anthy-context-kana-mode ac)))))
+       ac (anthy-lib-eucjp-to-utf8 (anthy-make-whole-string ac #t (anthy-context-kana-mode ac))))))
     (anthy-flush ac)
     (anthy-update-preedit ac)))
 
@@ -101,14 +105,14 @@
        ((anthy-context-converting ac)
 	(anthy-do-commit ac))
        ((anthy-context-transposing ac)
-	(im-commit ac (anthy-transposing-text ac))
+	(im-commit ac (anthy-lib-eucjp-to-utf8 (anthy-transposing-text ac)))
 	(anthy-flush ac))
        ((and
 	 (anthy-context-on ac)
 	 (anthy-has-preedit? ac)
 	 (not (= old-kana new-mode)))
 	(im-commit
-	 ac (anthy-make-whole-string ac #t (anthy-context-kana-mode ac)))
+	 ac (anthy-lib-eucjp-to-utf8 (anthy-make-whole-string ac #t (anthy-context-kana-mode ac))))
 	(anthy-flush ac)))
       (anthy-update-preedit ac))))
 
@@ -372,7 +376,8 @@
 	   (set! anthy-version (anthy-version->major.minor
 				(anthy-lib-get-anthy-version)))))
      (if anthy-lib-initialized?
-	 (anthy-context-set-ac-id! ac (anthy-lib-alloc-context)))
+	 (anthy-context-set-ac-id!
+	  ac (anthy-lib-alloc-context anthy-utf8-encoding)))
      (anthy-context-set-widgets! ac anthy-widgets)
      (anthy-context-set-rkc! ac rkc)
      (anthy-context-set-preconv-ustr! ac (ustr-new '()))
@@ -582,7 +587,7 @@
 	       (> (string-length preconv-str)
 		  0))
 	  (begin
-	    (anthy-lib-set-string ac-id preconv-str)
+	    (anthy-lib-set-string ac-id (anthy-lib-eucjp-to-utf8 preconv-str))
 	    (let ((nr-segments (anthy-lib-get-nr-segments ac-id)))
 	      (ustr-set-latter-seq! (anthy-context-segments ac)
 				    (make-list nr-segments 0))
@@ -708,16 +713,16 @@
        
        ;; direct key => commit
        (direct
-	(im-commit ac direct))
+	(im-commit ac (anthy-lib-eucjp-to-utf8 direct)))
 
        ;; space key => commit
        ((anthy-space-key? key key-state)
 	(if (anthy-context-alnum ac)
-	    (im-commit ac (list-ref
+	    (im-commit ac (anthy-lib-eucjp-to-utf8 (list-ref
 			   ja-alnum-space
 			   (- (anthy-context-alnum-type ac)
-			      anthy-type-halfwidth-alnum)))
-	    (im-commit ac (list-ref ja-space (anthy-context-kana-mode ac)))))
+			      anthy-type-halfwidth-alnum))))
+	    (im-commit ac (anthy-lib-eucjp-to-utf8 (list-ref ja-space (anthy-context-kana-mode ac))))))
 
        ((anthy-non-composing-symbol? ac key)
 	(anthy-commit-raw ac))
@@ -798,7 +803,7 @@
                (> (string-length preconv-str) 0)
                type)
         (begin
-          (anthy-lib-set-string ac-id preconv-str)
+          (anthy-lib-set-string ac-id (anthy-lib-eucjp-to-utf8 preconv-str))
           (expand-segment)
           (anthy-lib-commit-segment ac-id 0 type))))))
 
@@ -851,7 +856,7 @@
 	 (if (anthy-commit-key? key key-state)
 	     (begin
 	       (anthy-learn-transposing-text ac)
-	       (im-commit ac (anthy-transposing-text ac))
+	       (im-commit ac (anthy-lib-eucjp-to-utf8 (anthy-transposing-text ac)))
 	       (anthy-flush ac)
 	       #f)
 	     #t)
@@ -889,7 +894,7 @@
 	     #t)
 	 ; implicit commit
 	 (begin
-	   (im-commit ac (anthy-transposing-text ac))
+	   (im-commit ac (anthy-lib-eucjp-to-utf8 (anthy-transposing-text ac)))
 	   (anthy-flush ac)
 	   (anthy-proc-input-state ac key key-state))))))))
 
@@ -1139,7 +1144,7 @@
 	(begin
 	  (im-commit
 	   ac
-	   (anthy-make-whole-string ac #t (ja-opposite-kana kana)))
+	   (anthy-lib-eucjp-to-utf8 (anthy-make-whole-string ac #t (ja-opposite-kana kana))))
 	  (anthy-flush ac)))
 
        ;; Transposing状態へ移行
@@ -1157,7 +1162,7 @@
        ((anthy-hiragana-key? key key-state)
         (if (not (= kana anthy-type-hiragana))
 	  (begin
-	    (im-commit ac (anthy-make-whole-string ac #t kana))
+	    (im-commit ac (anthy-lib-eucjp-to-utf8 (anthy-make-whole-string ac #t kana)))
 	    (anthy-flush ac)))
 	(anthy-context-set-kana-mode! ac anthy-type-hiragana)
 	(anthy-context-set-alnum! ac #f))
@@ -1165,7 +1170,7 @@
        ((anthy-katakana-key? key key-state)
         (if (not (= kana anthy-type-katakana))
 	  (begin
-	    (im-commit ac (anthy-make-whole-string ac #t kana))
+	    (im-commit ac (anthy-lib-eucjp-to-utf8 (anthy-make-whole-string ac #t kana)))
 	    (anthy-flush ac)))
 	(anthy-context-set-kana-mode! ac anthy-type-katakana)
 	(anthy-context-set-alnum! ac #f))
@@ -1173,7 +1178,7 @@
        ((anthy-halfkana-key? key key-state)
         (if (not (= kana anthy-type-halfkana))
 	  (begin
-	    (im-commit ac (anthy-make-whole-string ac #t kana))
+	    (im-commit ac (anthy-lib-eucjp-to-utf8 (anthy-make-whole-string ac #t kana)))
 	    (anthy-flush ac)))
 	(anthy-context-set-kana-mode! ac anthy-type-halfkana)
 	(anthy-context-set-alnum! ac #f))
@@ -1201,7 +1206,7 @@
 	 (not (anthy-context-alnum ac))
 	 (anthy-kana-toggle-key? key key-state))
 	(begin
-	  (im-commit ac (anthy-make-whole-string ac #t kana))
+	  (im-commit ac (anthy-lib-eucjp-to-utf8 (anthy-make-whole-string ac #t kana)))
 	  (anthy-flush ac)
 	  (anthy-context-kana-toggle ac)))
 
@@ -1217,7 +1222,7 @@
 	(begin
 	  (im-commit
 	   ac
-	   (anthy-make-whole-string ac #t kana))
+	   (anthy-lib-eucjp-to-utf8 (anthy-make-whole-string ac #t kana)))
 	  (anthy-flush ac)))
 
        ;; left
@@ -1372,7 +1377,10 @@
 	 (not (anthy-context-predicting ac)))
 	(let* ((use-pending-rk-for-prediction? #f)
 	       (preconv-str
-		(anthy-make-whole-string ac #t (anthy-context-kana-mode ac)))
+		(anthy-make-whole-string
+		 ac
+		 (not use-pending-rk-for-prediction?)
+		 (anthy-context-kana-mode ac)))
 	       (ac-id (anthy-context-ac-id ac))
 	       (preedit-len
 		(+
@@ -1385,7 +1393,8 @@
 	       (>= preedit-len anthy-prediction-start-char-count)
 	       force-check?)
 	      (begin
-		(anthy-lib-set-prediction-src-string ac-id preconv-str)
+		(anthy-lib-set-prediction-src-string
+		 ac-id (anthy-lib-eucjp-to-utf8 preconv-str))
 		(let ((nr (anthy-lib-get-nr-predictions ac-id)))
 		  (if (and
 		       nr
@@ -1419,7 +1428,7 @@
 (define anthy-context-transposing-state-preedit
   (lambda (ac)
     (let ((transposing-text (anthy-transposing-text ac)))
-      (list (cons preedit-reverse transposing-text)
+      (list (cons preedit-reverse (anthy-lib-eucjp-to-utf8 transposing-text))
 	    (cons preedit-cursor "")))))
 
 (define anthy-transposing-text
@@ -1461,7 +1470,7 @@
     (let* ((preconv
 	    (ja-join-vu (string-to-list
 			 (anthy-make-whole-string ac #t anthy-type-hiragana))))
-	   (unconv-candidate (anthy-lib-get-unconv-candidate ac-id seg-idx))
+	   (unconv-candidate (anthy-lib-eucjp-to-utf8 (anthy-lib-get-unconv-candidate ac-id seg-idx)))
 	   (unconv (if unconv-candidate
 		       (ja-join-vu (string-to-list unconv-candidate))
 		       '()))
@@ -1513,7 +1522,7 @@
 			  preedit-underline))
 		(cand (if (> cand-idx anthy-candidate-type-halfwidth-alnum)
 			  (anthy-lib-get-nth-candidate ac-id seg-idx cand-idx)
-			  (anthy-get-raw-candidate ac ac-id seg-idx cand-idx)))
+			  (anthy-lib-eucjp-to-utf8 (anthy-get-raw-candidate ac ac-id seg-idx cand-idx))))
 		(seg (list (cons attr cand))))
 	   (if (and separator
 		    (< 0 seg-idx))
@@ -1537,15 +1546,15 @@
       (list
        (and (not (ustr-cursor-at-beginning? preconv-str))
 	    (cons preedit-underline
-		  (string-append-map-ustr-former extract-kana preconv-str)))
+		  (anthy-lib-eucjp-to-utf8 (string-append-map-ustr-former extract-kana preconv-str))))
        (and (> (string-length pending) 0)
-	    (cons preedit-underline pending))
+	    (cons preedit-underline (anthy-lib-eucjp-to-utf8 pending)))
        (and (anthy-has-preedit? ac)
 	    (cons preedit-cursor ""))
        (and (not (ustr-cursor-at-end? preconv-str))
 	    (cons
 	     preedit-underline
-	     (string-append-map-ustr-latter extract-kana preconv-str)))))))
+	     (anthy-lib-eucjp-to-utf8 (string-append-map-ustr-latter extract-kana preconv-str))))))))
 
 (define anthy-get-commit-string
   (lambda (ac)
@@ -1556,8 +1565,9 @@
 				  anthy-candidate-type-halfwidth-alnum)
 			       (anthy-lib-get-nth-candidate
 				ac-id seg-idx cand-idx)
-			       (anthy-get-raw-candidate
-				ac ac-id seg-idx cand-idx)))
+			       (anthy-lib-eucjp-to-utf8
+				(anthy-get-raw-candidate
+				ac ac-id seg-idx cand-idx))))
 			 (iota (ustr-length segments))
 			 (ustr-whole-seq segments)))))
 
@@ -1882,7 +1892,7 @@
 (register-im
  'anthy
  "ja"
- "EUC-JP"
+ "UTF-8"
  anthy-im-name-label
  anthy-im-short-desc
  #f
