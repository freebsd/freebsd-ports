--- aux/broker/src/subnet_type_info.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/subnet_type_info.hh
@@ -2,7 +2,7 @@
 #define BROKER_SUBNET_TYPE_INFO_HH
 
 #include "broker/subnet.hh"
-#include <caf/detail/abstract_uniform_type_info.hpp>
+#include <caf/abstract_uniform_type_info.hpp>
 #include <caf/serializer.hpp>
 #include <caf/deserializer.hpp>
 
@@ -12,11 +12,11 @@ namespace broker {
  * (de)serialization logic for type "subnet".
  */
 class subnet_type_info
-      : public caf::detail::abstract_uniform_type_info<subnet> {
+      : public caf::abstract_uniform_type_info<subnet> {
 public :
 
 	subnet_type_info()
-		: caf::detail::abstract_uniform_type_info<subnet>("broker::subnet")
+		: caf::abstract_uniform_type_info<subnet>("broker::subnet")
 		{}
 
 	void serialize(const void* ptr, caf::serializer* sink) const override
