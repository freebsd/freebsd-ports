--- goldlib/hunspell/affentry.hxx.orig	2018-01-26 22:46:50.173607000 +0000
+++ goldlib/hunspell/affentry.hxx	2018-01-26 22:47:27.023128000 +0000
@@ -25,7 +25,7 @@
   struct hentry *      check(const char * word, int len, char in_compound, 
                             const FLAG needflag = FLAG_NULL);
 
-  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = NULL);
+  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = 0);
 
   char *      check_morph(const char * word, int len, char in_compound,
                             const FLAG needflag = FLAG_NULL);
@@ -86,7 +86,7 @@
                     AffEntry* ppfx, char ** wlst, int maxSug, int * ns,
                     const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL);
 
-  struct hentry *   check_twosfx(const char * word, int len, int optflags, AffEntry* ppfx, const FLAG needflag = NULL);
+  struct hentry *   check_twosfx(const char * word, int len, int optflags, AffEntry* ppfx, const FLAG needflag = 0);
 
   char *      check_twosfx_morph(const char * word, int len, int optflags,
                  AffEntry* ppfx, const FLAG needflag = FLAG_NULL);
