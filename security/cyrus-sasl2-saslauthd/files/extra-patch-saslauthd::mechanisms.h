Index: saslauthd/mechanisms.h
diff -u saslauthd/mechanisms.h.orig saslauthd/mechanisms.h
--- saslauthd/mechanisms.h.orig	Sat Jul  5 15:41:07 2003
+++ saslauthd/mechanisms.h	Sat Jul  5 15:41:14 2003
@@ -52,7 +52,7 @@
  * Figure out which optional drivers we support.
  */
 #ifndef AUTH_KRB5
-# if defined(HAVE_KRB5_H)
+# if defined(HAVE_KRB5_H) && defined(STATIC_GSSAPIV2)
 #  define AUTH_KRB5
 # endif
 #endif
