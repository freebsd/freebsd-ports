--- src/api/egress_manager.cpp.orig	1970-01-01 00:00:00 UTC
+++ src/api/egress_manager.cpp
@@ -1,5 +1,6 @@
-#include <pichi/api/egress_manager.hpp>
 #include <pichi/config.hpp>
+// Include config.hpp first
+#include <pichi/api/egress_manager.hpp>
 
 using namespace std;
 
@@ -9,7 +10,7 @@ void EgressManager::update(string const& name, EgressV
 {
 #ifndef ENABLE_TLS
   assertFalse(vo.tls_.has_value() && *vo.tls_, PichiError::SEMANTIC_ERROR, "TLS not supported");
-#endif // ENABLE_TLS
+#endif  // ENABLE_TLS
   c_[name] = move(vo);
 }
 
@@ -25,4 +26,4 @@ EgressManager::ConstIterator EgressManager::end() cons
 
 EgressManager::ConstIterator EgressManager::find(string_view name) const { return c_.find(name); }
 
-} // namespace pichi::api
\ No newline at end of file
+}  // namespace pichi::api
