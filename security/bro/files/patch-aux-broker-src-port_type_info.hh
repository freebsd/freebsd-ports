--- aux/broker/src/port_type_info.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/port_type_info.hh
@@ -3,7 +3,7 @@
 
 #include "broker/port.hh"
 #include <type_traits>
-#include <caf/detail/abstract_uniform_type_info.hpp>
+#include <caf/abstract_uniform_type_info.hpp>
 #include <caf/serializer.hpp>
 #include <caf/deserializer.hpp>
 
@@ -12,12 +12,11 @@ namespace broker {
 /**
  * (de)serialization logic for type "port".
  */
-class port_type_info
-      : public caf::detail::abstract_uniform_type_info<port> {
+class port_type_info : public caf::abstract_uniform_type_info<port> {
 public :
 
 	port_type_info()
-		: caf::detail::abstract_uniform_type_info<port>("broker::port")
+		: caf::abstract_uniform_type_info<port>("broker::port")
 		{}
 
 	void serialize(const void* ptr, caf::serializer* sink) const override
