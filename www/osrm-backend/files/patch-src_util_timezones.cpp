--- src/util/timezones.cpp.orig	2020-11-03 05:31:40 UTC
+++ src/util/timezones.cpp
@@ -154,7 +154,7 @@ boost::optional<struct tm> Timezoner::op
 {
     std::vector<rtree_t::value_type> result;
     rtree.query(boost::geometry::index::intersects(point), std::back_inserter(result));
-    for (const auto v : result)
+    for (const auto& v : result)
     {
         const auto index = v.second;
         if (boost::geometry::within(point, local_times[index].first))
