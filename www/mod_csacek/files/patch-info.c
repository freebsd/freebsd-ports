--- info.c.orig	Sun Feb  3 12:13:41 2002
+++ info.c	Thu Dec  4 16:08:02 2003
@@ -267,11 +267,7 @@
 #endif
 
 	/* We are proud HTML 4.01 validated */
-	csa_add_output(p, "<p>\
-    <a href=\"http://validator.w3.org/check/referer\"><img border=\"0\"
-        src=\"http://www.w3.org/Icons/valid-html401\"
-        alt=\"Valid HTML 4.01!\" height=\"31\" width=\"88\"></a>
-  </p>\n", 0, CSA_OUT_STR);
+	csa_add_output(p, "<p>\ <a href=\"http://validator.w3.org/check/referer\"><img border=\"0\" src=\"http://www.w3.org/Icons/valid-html401\" alt=\"Valid HTML 4.01!\" height=\"31\" width=\"88\"></a> </p>\n", 0, CSA_OUT_STR);
 
 	csa_add_output(p, "</BODY>\n</HTML>", 0, CSA_OUT_STR);
 
