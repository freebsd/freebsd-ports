--- common/dbl1zhcn.dsl.orig	Sat Aug 21 05:25:09 2004
+++ common/dbl1zhcn.dsl	Sat Aug 21 05:25:47 2004
@@ -76,7 +76,7 @@
 	(list (normalize "bibliography") "%t")
 	(list (normalize "book")        "%t")
 	(list (normalize "chapter")     (if %chapter-autolabel%
-					    "&#181;&#218; %n &Chapter;"
+					    "\U-7B2C %n &Chapter;"
 					    "the &chapter; called %t"))
 	(list (normalize "equation")    "&Equation; %n")
 	(list (normalize "example")     "&Example; %n")
@@ -84,30 +84,30 @@
 	(list (normalize "glossary")    "%t")
 	(list (normalize "index")       "%t")
 	(list (normalize "listitem")    "%n")
-	(list (normalize "part")        "&#181;&#218; %n &Part;")
+	(list (normalize "part")        "\U-7B2C; %n &Part;")
 	(list (normalize "preface")     "%t")
 	(list (normalize "procedure")   "&Procedure; %n, %t")
 	(list (normalize "reference")   "&Reference; %n, %t")
 	(list (normalize "section")     (if %section-autolabel%
-					    "&#181;&#218; %n &section;"
+					    "\U-7B2C; %n &section;"
 					    "the &section; called %t"))
 	(list (normalize "sect1")       (if %section-autolabel%
-					    "&#181;&#218; %n &section;"
+					    "\U-7B2C; %n &section;"
 					    "the &section; called %t"))
 	(list (normalize "sect2")       (if %section-autolabel%
-					    "&#181;&#218; %n &section;"
+					    "\U-7B2C; %n &section;"
 					    "the &section; called %t"))
 	(list (normalize "sect3")       (if %section-autolabel%
-					    "&#181;&#218; %n &section;"
+					    "\U-7B2C; %n &section;"
 					    "the &section; called %t"))
 	(list (normalize "sect4")       (if %section-autolabel%
-					    "&#181;&#218; %n &section;"
+					    "\U-7B2C; %n &section;"
 					    "the &section; called %t"))
 	(list (normalize "sect5")       (if %section-autolabel%
-					    "&#181;&#218; %n &section;"
+					    "\U-7B2C; %n &section;"
 					    "the &section; called %t"))
 	(list (normalize "simplesect")  (if %section-autolabel%
-					    "&#181;&#218; %n &section;"
+					    "\U-7B2C; %n &section;"
 					    "the &section; called %t"))
 	(list (normalize "sidebar")     "&sidebar; %t")
 	(list (normalize "step")        "&step; %n")
