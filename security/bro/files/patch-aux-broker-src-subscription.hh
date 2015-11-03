--- aux/broker/src/subscription.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/subscription.hh
@@ -5,7 +5,8 @@
 #include "broker/util/optional.hh"
 #include "util/radix_tree.hh"
 #include <caf/actor.hpp>
-#include <caf/detail/abstract_uniform_type_info.hpp>
+#include <caf/actor_addr.hpp>
+#include <caf/abstract_uniform_type_info.hpp>
 #include <caf/serializer.hpp>
 #include <caf/deserializer.hpp>
 #include <unordered_map>
@@ -22,12 +23,11 @@ using topic_set = util::radix_tree<bool>
  * (de)serialization logic for type "topic_set".
  */
 class topic_set_type_info
-        : public caf::detail::abstract_uniform_type_info<topic_set> {
+        : public caf::abstract_uniform_type_info<topic_set> {
 public:
 
 	topic_set_type_info()
-		: caf::detail::abstract_uniform_type_info<topic_set>(
-	          "broker::topic_set")
+		: caf::abstract_uniform_type_info<topic_set>("broker::topic_set")
 		{}
 
 	void serialize(const void* ptr, caf::serializer* sink) const override;
