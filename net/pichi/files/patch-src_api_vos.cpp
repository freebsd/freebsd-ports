--- src/api/vos.cpp.orig	1970-01-01 00:00:00 UTC
+++ src/api/vos.cpp
@@ -1,3 +1,5 @@
+#include <pichi/config.hpp>
+// Include config.hpp first
 #include <numeric>
 #include <pichi/api/vos.hpp>
 #include <pichi/common.hpp>
@@ -57,7 +59,7 @@ static decltype(auto) keyFile_ = "key_file";
 static decltype(auto) destinations_ = "destinations";
 static decltype(auto) balance_ = "balance";
 
-} // namespace IngressVOKey
+}  // namespace IngressVOKey
 
 namespace EgressVOKey {
 
@@ -73,7 +75,7 @@ static decltype(auto) tls_ = "tls";
 static decltype(auto) insecure_ = "insecure";
 static decltype(auto) caFile_ = "ca_file";
 
-} // namespace EgressVOKey
+}  // namespace EgressVOKey
 
 namespace RuleVOKey {
 
@@ -84,20 +86,20 @@ static decltype(auto) pattern_ = "pattern";
 static decltype(auto) domain_ = "domain";
 static decltype(auto) country_ = "country";
 
-} // namespace RuleVOKey
+}  // namespace RuleVOKey
 
 namespace RouteVOKey {
 
 static decltype(auto) default_ = "default";
 static decltype(auto) rules_ = "rules";
 
-} // namespace RouteVOKey
+}  // namespace RouteVOKey
 
 namespace ErrorVOKey {
 
 static decltype(auto) message_ = "message";
 
-} // namespace ErrorVOKey
+}  // namespace ErrorVOKey
 
 namespace msg {
 
@@ -129,7 +131,7 @@ static auto const TOO_LONG_NAME_PASSWORD = "Name or pa
 static auto const MISSING_DESTINATIONS_FIELD = "Missiong destinations field"sv;
 static auto const MISSING_BALANCE_FIELD = "Missiong balance field"sv;
 
-} // namespace msg
+}  // namespace msg
 
 static DelayMode parseDelayMode(json::Value const& v)
 {
@@ -683,4 +685,4 @@ template <> RouteVO parse(json::Value const& v)
   return rvo;
 }
 
-} // namespace pichi::api
+}  // namespace pichi::api
