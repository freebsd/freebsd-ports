--- common/dbl1it.dsl.orig	Wed Jun 20 14:50:47 2001
+++ common/dbl1it.dsl	Thu Mar 13 23:01:54 2003
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
 
@@ -221,8 +222,8 @@
    (list (normalize "sect5")		"&Section;")
    (list (normalize "section")		"&Section;")
    (list (normalize "simplesect")	"&Section;")
-   (list (normalize "seeie")		"&See;")
-   (list (normalize "seealsoie")	"&Seealso;")
+   (list (normalize "seeie")		"&see;")
+   (list (normalize "seealsoie")	"&seealso;")
    (list (normalize "set")		"&Set;")
    (list (normalize "sidebar")		"&Sidebar;")
    (list (normalize "step")		"&step;")
@@ -441,9 +442,9 @@
 
 (define %gentext-it-table-endnotes% "&TableNotes;:")
 
-(define %gentext-it-index-see% "&See;")
+(define %gentext-it-index-see% "&see;")
 
-(define %gentext-it-index-seealso% "&SeeAlso;")
+(define %gentext-it-index-seealso% "&seealso;")
 
 
 (define (gentext-it-nav-prev prev) 
