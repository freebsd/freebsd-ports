--- aux/broker/src/store/result_type_info.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/store/result_type_info.hh
@@ -2,7 +2,7 @@
 #define BROKER_STORE_RESULT_TYPE_INFO_HH
 
 #include "broker/store/result.hh"
-#include <caf/detail/abstract_uniform_type_info.hpp>
+#include <caf/abstract_uniform_type_info.hpp>
 #include <caf/serializer.hpp>
 #include <caf/deserializer.hpp>
 
@@ -12,11 +12,11 @@ namespace broker { namespace store {
  * (de)serialization logic for type "result".
  */
 class result_type_info
-        : public caf::detail::abstract_uniform_type_info<result> {
+        : public caf::abstract_uniform_type_info<result> {
 public:
 
 	result_type_info()
-		: caf::detail::abstract_uniform_type_info<result>(
+		: caf::abstract_uniform_type_info<result>(
 	          "broker::store::result")
 		{}
 
