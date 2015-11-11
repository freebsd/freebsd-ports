--- aux/broker/src/peering_type_info.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/peering_type_info.hh
@@ -2,7 +2,7 @@
 #define BROKER_PEERING_TYPE_INFO_HH
 
 #include "peering_impl.hh"
-#include <caf/detail/abstract_uniform_type_info.hpp>
+#include <caf/abstract_uniform_type_info.hpp>
 #include <caf/serializer.hpp>
 #include <caf/deserializer.hpp>
 
@@ -11,12 +11,11 @@ namespace broker {
 /**
  * (de)serialization logic for type "peering".
  */
-class peering_type_info
-      : public caf::detail::abstract_uniform_type_info<peering> {
+class peering_type_info : public caf::abstract_uniform_type_info<peering> {
 public:
 
 	peering_type_info()
-		: caf::detail::abstract_uniform_type_info<peering>("broker::peering")
+		: caf::abstract_uniform_type_info<peering>("broker::peering")
 		{}
 
 	void serialize(const void* ptr, caf::serializer* sink) const override
