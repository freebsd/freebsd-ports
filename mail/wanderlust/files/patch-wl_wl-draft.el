--- wl/wl-draft.el.orig	2009-09-23 20:33:55.000000000 +0900
+++ wl/wl-draft.el	2009-09-23 20:34:31.000000000 +0900
@@ -147,10 +147,6 @@
 	     (if (eq wl-smtp-connection-type 'ssl)
 		 #'open-ssl-stream
 	       smtp-open-connection-function))
-	    (smtp-end-of-line
-	     (if (eq wl-smtp-connection-type 'ssl)
-		 "\n"
-	       smtp-end-of-line))
 	    smtp-sasl-user-name smtp-sasl-properties sasl-read-passphrase)
        (setq smtp-sasl-user-name wl-smtp-posting-user
 	     smtp-sasl-properties (when wl-smtp-authenticate-realm
