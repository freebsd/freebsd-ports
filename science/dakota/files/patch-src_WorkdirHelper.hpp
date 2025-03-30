- https://github.com/snl-dakota/dakota/pull/179

--- src/WorkdirHelper.hpp.orig	2025-03-30 07:11:51 UTC
+++ src/WorkdirHelper.hpp
@@ -17,6 +17,7 @@
 #include <boost/regex.hpp>
 #include <boost/iterator/filter_iterator.hpp>
 
+#include <boost/filesystem/directory.hpp>
 #include <boost/filesystem/operations.hpp>
 #include <boost/filesystem/path.hpp>
 namespace bfs = boost::filesystem;
