--- mew-ssl.el.orig	2018-05-26 06:07:04.349903000 +0900
+++ mew-ssl.el	2018-05-26 06:14:42.303658000 +0900
@@ -241,7 +241,7 @@
       (mew-ssl-set-string pnm string)
       (setq string (concat prev-str string))
       (cond
-       ((string-match "Negotiated \\|opened with SSL" string)
+       ((string-match "Negotiated \\| ciphersuite:\\|opened with SSL" string)
 	(mew-ssl-set-status pnm t))
        ((string-match "Failed to initialize" string)
 	(mew-ssl-set-status pnm t)) ;; xxx
