--- include/schily.h.orig	2008-04-26 16:53:01.000000000 +0200
+++ include/schily.h	2008-04-26 16:53:13.000000000 +0200
@@ -108,8 +108,6 @@ extern	int	fexecle __PR((const char *, F
 		/* 6th arg not const, fexecv forces av[ac] = NULL */
 extern	int	fexecv __PR((const char *, FILE *, FILE *, FILE *, int,
 							char **));
-extern	int	fexecve __PR((const char *, FILE *, FILE *, FILE *,
-					char * const *, char * const *));
 extern	int	fspawnv __PR((FILE *, FILE *, FILE *, int, char * const *));
 extern	int	fspawnl __PR((FILE *, FILE *, FILE *,
 					const char *, const char *, ...));
