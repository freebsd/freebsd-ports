--- core/src/dird/vbackup.cc	2023-04-07 16:02:23.780510000 -0500
+++ core/src/dird/vbackup.cc	2023-04-07 16:10:20.351116000 -0500
@@ -77,7 +77,7 @@
   std::vector<std::string> JobList;
   std::vector<std::string> JobsWithPurgedFiles;
 
-  bool operator()(int num_fields, char** row)
+  bool operator()([[maybe_unused]] int num_fields, char** row)
   {
     assert(num_fields == 5);
     JobList.push_back(row[col_JobId]);
