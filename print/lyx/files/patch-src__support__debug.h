libc++/C++11 support, obtained from NetBSD.
http://mail-index.netbsd.org/pkgsrc-changes/2013/05/09/msg088857.html
--- src/support/debug.h
+++ src/support/debug.h
@@ -17,14 +17,8 @@

 #include "support/strfwd.h"

-namespace std {
-
-class ios_base;
-
-template<typename CharT, typename Traits> class basic_streambuf;
-typedef basic_streambuf<char, char_traits<char> > streambuf;
-
-}
+#include <ios>
+#include <streambuf>


 namespace lyx {
