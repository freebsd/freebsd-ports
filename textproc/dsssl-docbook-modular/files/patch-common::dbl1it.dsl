--- common/dbl1it.dsl.orig	Wed Sep 18 10:13:28 2002
+++ common/dbl1it.dsl	Wed Sep 18 10:13:42 2002
@@ -22,6 +22,7 @@
 
 ;; Contributors:
 ;; camille@mandrakesoft.com
+;; sysadmin@alexdupre.com
 
 (define (it-author-string #!optional (author (current-node)))
   ;; Return a formatted string representation of the contents of:
@@ -64,7 +65,7 @@
 (define (it-xref-strings)
   (list (list (normalize "appendix")    (if %chapter-autolabel%
 					    "&Appendix; %n"
-					    "&appendix; %t"))
+					    "l'&appendix; intitolata %t"))
 	(list (normalize "article")     (string-append %gentext-it-start-quote%
 						       "%t"
 						       %gentext-it-end-quote%))
@@ -72,7 +73,7 @@
 	(list (normalize "book")        "%t")
 	(list (normalize "chapter")     (if %chapter-autolabel%
 					    "&Chapter; %n"
-					    "il &chapter; %t"))
+					    "&chapter; intitolato %t"))
 	(list (normalize "equation")    "&Equation; %n")
 	(list (normalize "example")     "&Example; %n")
 	(list (normalize "figure")      "&Figure; %n")
@@ -84,27 +85,27 @@
 	(list (normalize "procedure")   "&Procedure; %n, %t")
 	(list (normalize "reference")   "&Reference; %n, %t")
 	(list (normalize "section")     (if %section-autolabel%
-					    "la &Section; %n"
-					    "la &section; %t"))
+					    "&Section; %n"
+					    "la &section; intitolata %t"))
 	(list (normalize "sect1")       (if %section-autolabel%
-					    "la &Section; %n"
-					    "la &section; %t"))
+					    "&Section; %n"
+					    "la &section; intitolata %t"))
 	(list (normalize "sect2")       (if %section-autolabel%
-					    "la &Section; %n"
-					    "la &section; %t"))
+					    "&Section; %n"
+					    "la &section; intitolata %t"))
 	(list (normalize "sect3")       (if %section-autolabel%
-					    "la &Section; %n"
-					    "la &section; %t"))
+					    "&Section; %n"
+					    "la &section; intitolata %t"))
 	(list (normalize "sect4")       (if %section-autolabel%
-					    "la &Section; %n"
-					    "la &section; %t"))
+					    "&Section; %n"
+					    "la &section; intitolata %t"))
 	(list (normalize "sect5")       (if %section-autolabel%
-					    "la &Section; %n"
-					    "la &section; %t"))
+					    "&Section; %n"
+					    "la &section; intitolata %t"))
 	(list (normalize "simplesect")  (if %section-autolabel%
-					    "la &Section; %n"
-					    "la &section; %t"))
-	(list (normalize "sidebar")     "the &sidebar; %t")
+					    "&Section; %n"
+					    "la &section; intitolata %t"))
+	(list (normalize "sidebar")     "&sidebar; %t")
 	(list (normalize "step")        "&step; %n")
 	(list (normalize "table")       "&Table; %n")))
 
