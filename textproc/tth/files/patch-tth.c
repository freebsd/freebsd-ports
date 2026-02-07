--- tth.c.orig	2022-11-18 20:34:51 UTC
+++ tth.c
@@ -20534,7 +20534,7 @@ YY_RULE_SETUP
 \\def\\tthciteform#1#2#3#4{\\ifNAT@numbers#1\\else\\ #3, [#2\\fi}\
 \\def\\tthciteob{\\ifNAT@numbers[\\else\\fi}\
 \\def\\tthciteib{\\ifNAT@numbers\\else]\\fi}\\def\\tthcitecb{]}\
-\\input tthntbib.sty");
+\\input %%DATADIR%%/styles/tthntbib.sty");
 }
 	YY_BREAK
 case 596:
