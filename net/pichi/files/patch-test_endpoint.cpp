--- test/endpoint.cpp.orig	1970-01-01 00:00:00 UTC
+++ test/endpoint.cpp
@@ -132,7 +132,8 @@ BOOST_AUTO_TEST_CASE(serialize_Domain)
 #ifndef HAS_CLASS_TEMPLATE_ARGUMENT_DEDUCTION
       <uint8_t, 13>
 #endif // HAS_CLASS_TEMPLATE_ARGUMENT_DEDUCTION
-      {0x03, 0x09, 'l', 'o', 'c', 'a', 'l', 'h', 'o', 's', 't', 0x01, 0xbb};
+      {0x03_u8, 0x09_u8, 0x6c_u8, 0x6f_u8, 0x63_u8, 0x61_u8, 0x6c_u8,
+       0x68_u8, 0x6f_u8, 0x73_u8, 0x74_u8, 0x01_u8, 0xbb_u8};
 
   auto fact = array<uint8_t, 13>{};
   auto len = serializeEndpoint(makeEndpoint(host, port), fact);
