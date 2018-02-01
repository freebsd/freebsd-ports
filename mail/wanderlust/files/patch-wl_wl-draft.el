--- wl/wl-draft.el.orig	2005-03-20 13:10:03 UTC
+++ wl/wl-draft.el
@@ -147,10 +147,6 @@ e.g.
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
