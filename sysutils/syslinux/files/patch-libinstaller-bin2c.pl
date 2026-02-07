--- libinstaller/bin2c.pl.orig	2010-10-20 21:25:38.000000000 +0200
+++ libinstaller/bin2c.pl	2010-11-16 14:24:32.427122941 +0100
@@ -27,7 +27,7 @@
 
 $pad = 1 if ($pad < 1);
 
-printf "unsigned char %s[] = {\n", $table_name;
+printf "static unsigned char _%s[] = {\n", $table_name;
 
 $pos = 0;
 $linelen = 8;
@@ -74,5 +74,6 @@
 @st = stat STDIN;
 
 printf "\nconst int %s_mtime = %d;\n", $table_name, $st[9];
+printf "\nunsigned char *%s = _%s;\n", $table_name, $table_name;
 
 exit 0;
