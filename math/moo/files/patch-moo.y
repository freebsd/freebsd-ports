--- moo.y.orig	2016-06-04 10:05:27 UTC
+++ moo.y
@@ -4,6 +4,11 @@
  * Public domain.
  */
 
+#ifdef HAVE_CAPSICUM
+#include <sys/capsicum.h>
+#include <capsicum_helpers.h>
+#endif
+
 #include <ctype.h>
 #include <err.h>
 #include <errno.h>
@@ -34,7 +39,7 @@ static int used_oct;
 
 static void		divbyzero(void);
 static void		printnum(int64_t);
-__dead static void	usage(void);
+__dead2 static void	usage(void);
 void			yyerror(char *);
 int			yylex(void);
 int			yyparse(void);
@@ -315,10 +320,16 @@ getnum(const char *nptr)
 int
 main(int argc, char *argv[])
 {
-	int ch;
+#ifdef HAVE_CAPSICUM
+    if (caph_limit_stdio() < 0)
+        err(1, "unable to limit capabilities for stdio");
 
-	if (pledge("stdio tmppath", NULL) == -1)
-		err(1, "pledge");
+    caph_cache_catpages();
+    if (cap_enter() < 0 && errno != ENOSYS)
+        err(1, "unable to enter capability mode");
+#endif
+
+	int ch;
 
 	while ((ch = getopt(argc, argv, "0123456789b:lsuw:")) != -1)
 		switch (ch) {
@@ -403,9 +414,6 @@ DONEPARSING:
 		yyin = sfp;
 	}
 
-	if (pledge("stdio", NULL) == -1)
-		err(1, "pledge");
-
 	yyparse();
 
 	return (0);
