--- conf.cpp.orig	2023-05-04 07:34:30 UTC
+++ conf.cpp
@@ -35,6 +35,8 @@ any later version.
 #include <string.h>
 #include <unistd.h>
 
+#define program_invocation_name getprogname()
+
 using namespace std;
 
 /* true if locate(1) should check whether files are visible before reporting
