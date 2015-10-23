--- aux/broker/src/data_type_info.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/data_type_info.hh
@@ -2,7 +2,7 @@
 #define BROKER_DATA_TYPE_INFO_HH
 
 #include "broker/data.hh"
-#include <caf/detail/abstract_uniform_type_info.hpp>
+#include <caf/abstract_uniform_type_info.hpp>
 #include <caf/serializer.hpp>
 #include <caf/deserializer.hpp>
 
@@ -11,11 +11,11 @@ namespace broker {
 /**
  * (de)serialization logic for type "data".
  */
-class data_type_info : public caf::detail::abstract_uniform_type_info<data> {
+class data_type_info : public caf::abstract_uniform_type_info<data> {
 public:
 
 	data_type_info()
-		: caf::detail::abstract_uniform_type_info<data>("broker::data")
+		: caf::abstract_uniform_type_info<data>("broker::data")
 		{}
 
 	struct serializer {
@@ -58,11 +58,11 @@ public:
  * (de)serialization logic for type "optional<data>".
  */
 class optional_data_type_info :
-      public caf::detail::abstract_uniform_type_info<util::optional<data>> {
+      public caf::abstract_uniform_type_info<util::optional<data>> {
 public:
 
 	optional_data_type_info()
-		: caf::detail::abstract_uniform_type_info<util::optional<data>>(
+		: caf::abstract_uniform_type_info<util::optional<data>>(
 	          "broker::util::optional<data>")
 		{}
 
