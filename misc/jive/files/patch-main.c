--- main.c.orig	1997-02-03 10:59:32.000000000 +0000
+++ main.c
@@ -7,7 +7,7 @@ char *yylex();
 int main()
 {
 	char *line;
-	while(line = yylex()){
+	while((line = yylex())){
 		printf("%s", line);
 	}
 	return 0;
