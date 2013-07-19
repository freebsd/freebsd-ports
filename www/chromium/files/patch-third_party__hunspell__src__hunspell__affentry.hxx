--- third_party/hunspell/src/hunspell/affentry.hxx	2013-07-03 23:52:32.000000000 -0400
+++ third_party/hunspell/src/hunspell/affentry.hxx	2013-07-19 01:31:57.000000000 -0400
@@ -27,7 +27,7 @@
   struct hentry *      checkword(const char * word, int len, char in_compound, 
                             const FLAG needflag = FLAG_NULL);
 
-  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = NULL);
+  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = 0);
 
   char *      check_morph(const char * word, int len, char in_compound,
                             const FLAG needflag = FLAG_NULL);
@@ -90,7 +90,7 @@
 //                    const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL, char in_compound=IN_CPD_NOT);
                     const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL, const FLAG badflag = 0);
 
-  struct hentry *   check_twosfx(const char * word, int len, int optflags, PfxEntry* ppfx, const FLAG needflag = NULL);
+  struct hentry *   check_twosfx(const char * word, int len, int optflags, PfxEntry* ppfx, const FLAG needflag = 0);
 
   char *      check_twosfx_morph(const char * word, int len, int optflags,
                  PfxEntry* ppfx, const FLAG needflag = FLAG_NULL);
