--- src/base64.hpp.orig	2015-04-22 19:37:22 UTC
+++ src/base64.hpp
@@ -147,7 +147,7 @@ namespace base64 {
 						Warning("base64 decode error: unexpected fill char -- offset read?");
 						return false;
 					}
-					if(!(isspace(data[i-1]))) {
+					if(!(std::isspace(data[i-1]))) {
 						//cerr << "base 64 decode error: illegal character '" << data[i-1] << "' (0x" << std::hex << (int)data[i-1] << std::dec << ")" << endl;
 						Warning("base 64 decode error: illegal character");
 						return false;
@@ -165,7 +165,7 @@ namespace base64 {
 						Warning("base64 decode error: unexpected fill char -- offset read?");
 						return false;
 					}
-					if(!(isspace(data[i-1]))) {
+					if(!(std::isspace(data[i-1]))) {
 						//cerr << "base 64 decode error: illegal character '" << data[i-1] << '\'' << endl;
 						Warning("base 64 decode error: illegal character");
 						return false;
@@ -190,7 +190,7 @@ namespace base64 {
 					if(fillchar == data[i-1]) {
 						return true;
 					}
-					if((!isspace(data[i-1]))) {
+					if((!std::isspace(data[i-1]))) {
 						//cerr << "base 64 decode error: illegal character '" << data[i-1] << '\'' << endl;
 						Warning("base 64 decode error: illegal character");
 						return false;
@@ -215,7 +215,7 @@ namespace base64 {
 					if(fillchar == data[i-1]) {
 						return true;
 					}
-					if(!(isspace(data[i-1]))) {
+					if(!(std::isspace(data[i-1]))) {
 						//cerr << "base 64 decode error: illegal character '" << data[i-1] << '\'' << endl;
 						Warning("base 64 decode error: illegal character");
 						return false;
