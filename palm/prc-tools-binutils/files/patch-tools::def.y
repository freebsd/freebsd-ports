--- ../prc-tools-2.0/tools/def.y.orig	Tue Jan 25 12:10:57 2000
+++ ../prc-tools-2.0/tools/def.y	Thu Nov 28 10:17:15 2002
@@ -138,6 +138,7 @@

 trap_def:
 	  TRAP '{' trap_list '}'
+	;

 trap_list:
 	  /* empty */		{ $$ = 1000; }
