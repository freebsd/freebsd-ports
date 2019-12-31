--- goldlib/hunspell/affentry.hxx.orig	2006-04-05 17:20:12 UTC
+++ goldlib/hunspell/affentry.hxx
@@ -25,7 +25,7 @@ class PfxEntry : public AffEntry (public)
   struct hentry *      check(const char * word, int len, char in_compound, 
                             const FLAG needflag = FLAG_NULL);
 
-  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = NULL);
+  struct hentry *      check_twosfx(const char * word, int len, char in_compound, const FLAG needflag = 0);
 
   char *      check_morph(const char * word, int len, char in_compound,
                             const FLAG needflag = FLAG_NULL);
@@ -86,7 +86,7 @@ class SfxEntry : public AffEntry (public)
                     AffEntry* ppfx, char ** wlst, int maxSug, int * ns,
                     const FLAG cclass = FLAG_NULL, const FLAG needflag = FLAG_NULL);
 
-  struct hentry *   check_twosfx(const char * word, int len, int optflags, AffEntry* ppfx, const FLAG needflag = NULL);
+  struct hentry *   check_twosfx(const char * word, int len, int optflags, AffEntry* ppfx, const FLAG needflag = 0);
 
   char *      check_twosfx_morph(const char * word, int len, int optflags,
                  AffEntry* ppfx, const FLAG needflag = FLAG_NULL);
