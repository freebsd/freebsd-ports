--- hpt/src/perl.c.orig	2020-01-16 21:50:04 UTC
+++ hpt/src/perl.c
@@ -109,10 +109,12 @@ extern "C" {
 # define min(a, b)      ((a) < (b) ? (a) : (b))
 #endif
 
+#if 0
 #ifdef __GNUC__
 # ifdef _OLDPERL_
 #  define Perl___notused Perl___notused __attribute__ ((unused))
 # endif
+#endif
 #endif
 
 #ifndef LL_PERL
