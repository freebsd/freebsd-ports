--- ./src/bmff/typebmff.cpp.orig	2009-07-14 03:07:10.000000000 +0400
+++ ./src/bmff/typebmff.cpp	2012-01-15 22:14:12.057757646 +0400
@@ -23,19 +23,12 @@
 
 #include "impl.h"
 
-// VStudio idiocy prevents defining template instanced static data
-// in a namespace. Workaround it by defining in global scope.
-// Other platforms will continue to put things in the proper namespace.
-#if defined( _MSC_VER )
-using namespace mp4v2::impl::bmff;
-#else
-namespace mp4v2 { namespace impl { namespace bmff {
-#endif
+namespace mp4v2 { namespace impl {
 
 ///////////////////////////////////////////////////////////////////////////////
 
 template <>
-const EnumLanguageCode::Entry EnumLanguageCode::data[] = {
+const bmff::EnumLanguageCode::Entry bmff::EnumLanguageCode::data[] = {
     { mp4v2::impl::bmff::ILC_AAR,  "aar",  "Afar" },
     { mp4v2::impl::bmff::ILC_ABK,  "abk",  "Abkhazian" },
     { mp4v2::impl::bmff::ILC_ACE,  "ace",  "Achinese" },
@@ -526,9 +519,7 @@
 
 ///////////////////////////////////////////////////////////////////////////////
 
-#if defined( _MSC_VER )
-namespace mp4v2 { namespace impl { namespace bmff {
-#endif
+namespace bmff {
 
 ///////////////////////////////////////////////////////////////////////////////
 
