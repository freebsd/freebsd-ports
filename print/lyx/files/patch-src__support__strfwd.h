libc++/C++11 support, obtained from NetBSD.
http://mail-index.netbsd.org/pkgsrc-changes/2012/11/23/msg081094.html
--- src/support/strfwd.h
+++ src/support/strfwd.h
@@ -29,26 +29,8 @@ namespace lyx { typedef boost::uint32_t char_type; }
 #endif
 
 
-namespace std {
-
-template<typename Alloc> class allocator;
-
-template<typename Char> struct char_traits;
-template<> struct char_traits<char>;
-#ifdef USE_WCHAR_T
-template<> struct char_traits<wchar_t>;
-#endif
-
-template<typename Char, typename Traits, typename Alloc> class basic_string;
-typedef basic_string<char, char_traits<char>, allocator<char> > string;
-
-template<class Char, class Traits> class basic_istream;
-template<class Char, class Traits> class basic_ostream;
-
-typedef basic_istream<char, char_traits<char> > istream;
-typedef basic_ostream<char, char_traits<char> > ostream;
-
-} // namepace std
+#include <iostream>
+#include <string>
 
 
 namespace lyx {
