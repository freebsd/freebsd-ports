diff -ruw src/intrface.c src/intrface.c
--- src/intrface.c	2004-03-16 11:13:01.000000000 +0100
+++ src/intrface.c	2004-03-30 17:19:00.000000000 +0200
@@ -788,9 +788,6 @@
 		int done=0;
 		va_list ap;
 		WINDOW *window;
-		va_start(ap,_format);
-		window=*(WINDOW**)ap;
-		va_end(ap);
 		struct MenuItem menuBuffer[]=
 		{
 		  { 'P', "Previous",""},
@@ -806,6 +803,9 @@
 		  { 0, NULL, NULL }
 		};
 		char options[20];
+		va_start(ap,_format);
+		window=va_arg(ap,WINDOW*);
+		va_end(ap);
 		if(nbr_lines<=DUMP_MAX_LINES)
 		{
 		  strncpy(options,"Q",sizeof(options));
