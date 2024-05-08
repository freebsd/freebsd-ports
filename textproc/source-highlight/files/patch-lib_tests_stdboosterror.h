--- lib/tests/stdboosterror.h.orig	2019-06-02 15:22:17 UTC
+++ lib/tests/stdboosterror.h
@@ -4,7 +4,7 @@ static boost::regex_error
 #include <boost/regex/pattern_except.hpp>
 
 static boost::regex_error
-        std_boost_exception(boost::regex_error(boost::regex_constants::error_bad_pattern));
+        std_boost_exception{boost::regex_error(boost::regex_constants::error_bad_pattern)};
 
 /**
  * returns the string representing a standard exception (which
