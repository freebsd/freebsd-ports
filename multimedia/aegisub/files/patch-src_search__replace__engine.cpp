After https://github.com/boostorg/range/commit/69409ed63a9e1 build fails:

src/search_replace_engine.cpp:315:14: error: call to
      'distance' is ambiguous
                                count += distance(
                                         ^~~~~~~~
/usr/include/c++/v1/iterator:511:1: note: candidate function [with _InputIter =
      boost::u32regex_iterator<std::__1::__wrap_iter<const char *> >]
distance(_InputIter __first, _InputIter __last)
^
/usr/local/include/boost/iterator/distance.hpp:49:9: note: candidate function [with SinglePassIterator =
      boost::u32regex_iterator<std::__1::__wrap_iter<const char *> >]
        distance(SinglePassIterator first, SinglePassIterator last)
        ^

--- src/search_replace_engine.cpp.orig	2014-12-08 00:07:09 UTC
+++ src/search_replace_engine.cpp
@@ -312,7 +312,7 @@
 			if (MatchState ms = matches(&diag, 0)) {
 				auto& diag_field = diag.*get_dialogue_field(settings.field);
 				std::string const& text = diag_field.get();
-				count += distance(
+				count += std::distance(
 					boost::u32regex_iterator<std::string::const_iterator>(begin(text), end(text), *ms.re),
 					boost::u32regex_iterator<std::string::const_iterator>());
 				diag_field = u32regex_replace(text, *ms.re, settings.replace_with);
