In file included from qgpgmebackend.cpp:42:0:
../../../lang/cpp/src/engineinfo.h: In constructor 'GpgME::EngineInfo::Version::Version(const string&)':
../../../lang/cpp/src/engineinfo.h:47:17: error: 'sscanf' is not a member of 'std'
                 std::sscanf(version.c_str(), "%d.%d.%d", &major, &minor, &patch) != 3) {
                 ^


--- lang/cpp/src/engineinfo.h.orig	2016-11-20 11:59:52 UTC
+++ lang/cpp/src/engineinfo.h
@@ -30,6 +30,7 @@
 #include <algorithm>
 #include <string>
 #include <iostream>
+#include <cstdio>
 
 namespace GpgME
 {
