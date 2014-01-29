--- libcudf/src/dependency.cpp.orig	2014-01-10 15:13:07.000000000 +0000
+++ libcudf/src/dependency.cpp	2014-01-10 15:29:32.000000000 +0000
@@ -49,6 +49,7 @@
     struct CudfPackageRefFilter
     {
         CudfPackageRefFilter(const Cudf::PackageRef &ref) : ref(ref) { }
+		CudfPackageRefFilter &operator = (const CudfPackageRefFilter &t) { return *this; } 
         bool operator()(const Entity *entity)
         {
             switch(ref.op)
