$NetBSD$

--- ./src/BoostFormat.h.orig    2002-11-25 12:44:44.000000000 -0700
+++ ./src/BoostFormat.h
@@ -15,7 +15,7 @@ namespace boost
 {

 extern
-template basic_format<char>;
+template class basic_format<char>;

 extern template
 std::ostream &
