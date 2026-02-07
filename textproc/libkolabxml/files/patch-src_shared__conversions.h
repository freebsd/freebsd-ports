Fix build with devel/xsd >= 4.2.0

--- src/shared_conversions.h.orig	2023-12-16 04:50:40 UTC
+++ src/shared_conversions.h
@@ -29,7 +29,7 @@ typedef ::xsd::cxx::tree::type type;
 typedef boost::shared_ptr<cDateTime> cDateTimePtr;
 
 typedef ::xsd::cxx::tree::type type;
-#if (XSD_INT_VERSION >= 4000000L)
+#if (LIBXSD_VERSION >= 4000000L)
 typedef ::xsd::cxx::tree::simple_type< char, type > simple_type;
 #else
 typedef ::xsd::cxx::tree::simple_type< type > simple_type;
