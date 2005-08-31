--- generic/proof-menu.el.orig	Fri Jul 22 17:46:09 2005
+++ generic/proof-menu.el	Fri Jul 22 17:46:09 2005
@@ -176,10 +176,10 @@
 	     (cons "Help"
 		   (append
 		    `([,(concat proof-assistant " information")
-		       '(proof-help)
+		        (proof-help)
 		       ,menuvisiblep proof-info-command]
 		      [,(concat proof-assistant " web page")
-		       '(browse-url proof-assistant-home-page)
+		        (browse-url proof-assistant-home-page)
 		       ,menuvisiblep proof-assistant-home-page])
 		    (proof-ass help-menu-entries))))))))
 
