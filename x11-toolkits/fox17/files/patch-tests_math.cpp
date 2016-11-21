--- tests/math.cpp.orig	2016-01-18 02:25:42 UTC
+++ tests/math.cpp
@@ -105,7 +105,6 @@ static const char *const names[]={
   "atanh",
   "expm1",
   "exp2",
-  "exp10",
   "log1p",
   "log2"
   };
@@ -128,7 +127,6 @@ static const DBLFUNS dblfuns[]={
   {Math::atanh,     ::atanh},
   {Math::expm1,     ::expm1},
   {Math::exp2,      ::exp2},
-  {Math::exp10,     ::exp10},
   {Math::log1p,     ::log1p},
   {Math::log2,      ::log2},
   };
@@ -151,7 +149,6 @@ static const FLTFUNS fltfuns[]={
   {Math::atanh,     ::atanhf},
   {Math::expm1,     ::expm1f},
   {Math::exp2,      ::exp2f},
-  {Math::exp10,     ::exp10f},
   {Math::log1p,     ::log1pf},
   {Math::log2,      ::log2f},
   };
