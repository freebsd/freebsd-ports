commit 67c298c36f69b6906840b7584be06b7b5f33f829
Author: Paul Eggert <eggert@cs.ucla.edu>
Date:   2024-01-16T17:21:08-08:00

    posixtm: pacify clang 18
    
    Problem reported by Khem Raj in:
    https://lists.gnu.org/r/bug-gnulib/2024-01/msg00045.html
    * lib/posixtm.c (posixtime): Pacify clang 18 by converting bool to int.
    Arguably this is a bug in draft C2x, since the non-pointer args to
    ckd_add should promote just like any other expressions do;
    but thats not clangs fault.

--- lib/posixtm.c.orig	2023-01-01 13:39:11 UTC
+++ lib/posixtm.c
@@ -191,7 +191,7 @@ posixtime (time_t *p, const char *s, unsigned int synt
              | (tm0.tm_min ^ tm1.tm_min)
              | (tm0.tm_sec ^ tm1.tm_sec)))
         {
-          if (ckd_add (&t, t, leapsec))
+          if (ckd_add (&t, t, +leapsec))
             return false;
           *p = t;
           return true;
