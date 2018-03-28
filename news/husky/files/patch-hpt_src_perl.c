--- hpt/src/perl.c.orig	2018-03-28 16:01:18 UTC
+++ hpt/src/perl.c
@@ -109,9 +109,9 @@ extern "C" {
 # define min(a, b)      ((a) < (b) ? (a) : (b))
 #endif
 
-#ifdef __GNUC__
+/*#ifdef __GNUC__
 # define Perl___notused Perl___notused __attribute__ ((unused))
-#endif
+#endif*/
 
 #ifndef LL_PERL
 # define LL_PERL LL_EXEC
