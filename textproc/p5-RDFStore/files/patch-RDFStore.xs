--- RDFStore.xs.orig	2006-06-19 10:00:51 UTC
+++ RDFStore.xs
@@ -54,9 +54,6 @@ static PerlInterpreter *my_perl;
 
 #ifndef DB_VERSION_MAJOR
 
-#undef  dNOOP
-#define dNOOP extern int Perl___notused
-
 /* Ditto for dXSARGS. */
 #undef  dXSARGS
 #define dXSARGS                             \
