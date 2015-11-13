--- aux/broker/src/store/value_type_info.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/store/value_type_info.hh
@@ -2,7 +2,7 @@
 #define BROKER_STORE_VALUE_TYPE_INFO_HH
 
 #include "broker/store/value.hh"
-#include <caf/detail/abstract_uniform_type_info.hpp>
+#include <caf/abstract_uniform_type_info.hpp>
 #include <caf/serializer.hpp>
 #include <caf/deserializer.hpp>
 
@@ -12,12 +12,11 @@ namespace broker { namespace store {
  * (de)serialization logic for type "value".
  */
 class value_type_info
-        : public caf::detail::abstract_uniform_type_info<value> {
+        : public caf::abstract_uniform_type_info<value> {
 public:
 
     value_type_info()
-		: caf::detail::abstract_uniform_type_info<value>(
-	          "broker::store::value")
+		: caf::abstract_uniform_type_info<value>("broker::store::value")
 		{}
 
 	void serialize(const void* ptr, caf::serializer* sink) const override
