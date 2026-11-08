-- fix discovery of boost - minor latest was too low and boost's version has outgrew it
-- https://github.com/ossia/score/issues/2273

--- 3rdparty/libossia/cmake/deps/boost.cmake.orig	2026-03-27 08:02:46 UTC
+++ 3rdparty/libossia/cmake/deps/boost.cmake
@@ -1,5 +1,5 @@ set(BOOST_MINOR_MINIMAL 87)
 set(BOOST_MINOR_MINIMAL 87)
-set(BOOST_MINOR_LATEST 90)
+set(BOOST_MINOR_LATEST 100)
 
 unset(BOOST_VERSIONS_LIST)
 set(current_val ${BOOST_MINOR_LATEST})
