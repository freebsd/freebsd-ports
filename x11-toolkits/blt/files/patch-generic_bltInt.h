--- generic/bltInt.h.orig	2010-12-10 23:41:18.000000000 +0100
+++ generic/bltInt.h	2013-11-19 09:15:34.000000000 +0100
@@ -275,7 +275,7 @@
 
 #define free(x)		abc123(x)
 
-extern int Blt_DictionaryCompare _ANSI_ARGS_((char *s1, char *s2));
+extern int Blt_DictionaryCompare _ANSI_ARGS_((CONST char *s1, CONST char *s2));
 
 EXTERN void Blt_Panic _ANSI_ARGS_(TCL_VARARGS(char *, args));
 
@@ -379,7 +379,7 @@
 
 #ifdef TCL_UTF_MAX
 #define HAVE_UTF	1
-extern FILE *Blt_OpenUtfFile _ANSI_ARGS_((char *fileName, char *mode));
+extern FILE *Blt_OpenUtfFile _ANSI_ARGS_((CONST char *fileName, CONST char *mode));
 #define fopen(f,m)	Blt_OpenUtfFile((f),(m));
 #else
 #define HAVE_UTF	0
