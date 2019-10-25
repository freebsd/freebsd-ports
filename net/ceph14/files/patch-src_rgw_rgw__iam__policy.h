diff --git a/src/rgw/rgw_iam_policy.h b/src/rgw/rgw_iam_policy.h
index f6269dbef6ac..00048b4a7af0 100644
--- src/rgw/rgw_iam_policy.h
+++ src/rgw/rgw_iam_policy.h
@@ -9,7 +9,6 @@
 #include <cstdint>
 #include <iostream>
 #include <string>
-#include <bitset>
 
 #include <boost/algorithm/string/predicate.hpp>
 #include <boost/container/flat_map.hpp>
@@ -125,7 +124,7 @@ static constexpr std::uint64_t stsAll = 79;
 static constexpr std::uint64_t s3Count = s3BypassGovernanceRetention + 1;
 static constexpr std::uint64_t allCount = stsAll + 1;
 
-using Action_t = bitset<allCount>;
+using Action_t = std::bitset<allCount>;
 using NotAction_t = Action_t;
 
 static const Action_t None(0);
