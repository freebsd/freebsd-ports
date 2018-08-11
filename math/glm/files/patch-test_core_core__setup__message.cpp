--- test/core/core_setup_message.cpp.orig	2018-08-09 13:49:13 UTC
+++ test/core/core_setup_message.cpp
@@ -10,12 +10,6 @@ int test_compiler()
 	{
 		switch(GLM_COMPILER)
 		{
-		case GLM_COMPILER_VC10:
-			std::printf("Visual C++ 10 - 2010\n");
-			break;
-		case GLM_COMPILER_VC11:
-			std::printf("Visual C++ 11 - 2012\n");
-			break;
 		case GLM_COMPILER_VC12:
 			std::printf("Visual C++ 12 - 2013\n");
 			break;
@@ -23,7 +17,10 @@ int test_compiler()
 			std::printf("Visual C++ 14 - 2015\n");
 			break;
 		case GLM_COMPILER_VC15:
-			std::printf("Visual C++ 15 - 201X\n");
+			std::printf("Visual C++ 15 - 2017\n");
+			break;
+		case GLM_COMPILER_VC16:
+			std::printf("Visual C++ 16 - 20XX\n");
 			break;
 		default:
 			std::printf("Visual C++ version not detected\n");
@@ -35,12 +32,6 @@ int test_compiler()
 	{
 		switch(GLM_COMPILER)
 		{
-		case GLM_COMPILER_GCC44:
-			std::printf("GCC 4.4\n");
-			break;
-		case GLM_COMPILER_GCC45:
-			std::printf("GCC 4.5\n");
-			break;
 		case GLM_COMPILER_GCC46:
 			std::printf("GCC 4.6\n");
 			break;
@@ -53,41 +44,17 @@ int test_compiler()
 		case GLM_COMPILER_GCC49:
 			std::printf("GCC 4.9\n");
 			break;
-		case GLM_COMPILER_GCC50:
-			std::printf("GCC 5.0\n");
-			break;
-		case GLM_COMPILER_GCC51:
-			std::printf("GCC 5.1\n");
-			break;
-		case GLM_COMPILER_GCC52:
-			std::printf("GCC 5.2\n");
-			break;
-		case GLM_COMPILER_GCC53:
-			std::printf("GCC 5.3\n");
-			break;
-		case GLM_COMPILER_GCC54:
-			std::printf("GCC 5.4\n");
-			break;
-		case GLM_COMPILER_GCC60:
-			std::printf("GCC 6.0\n");
-			break;
-		case GLM_COMPILER_GCC61:
-			std::printf("GCC 6.1\n");
-			break;
-		case GLM_COMPILER_GCC62:
-			std::printf("GCC 6.2\n");
-			break;
-		case GLM_COMPILER_GCC70:
-			std::printf("GCC 7.0\n");
+		case GLM_COMPILER_GCC5:
+			std::printf("GCC 5\n");
 			break;
-		case GLM_COMPILER_GCC71:
-			std::printf("GCC 7.1\n");
+		case GLM_COMPILER_GCC6:
+			std::printf("GCC 6\n");
 			break;
-		case GLM_COMPILER_GCC72:
-			std::printf("GCC 7.2\n");
+		case GLM_COMPILER_GCC7:
+			std::printf("GCC 7\n");
 			break;
-		case GLM_COMPILER_GCC80:
-			std::printf("GCC 8.0\n");
+		case GLM_COMPILER_GCC8:
+			std::printf("GCC 8\n");
 			break;
 		default:
 			std::printf("GCC version not detected\n");
@@ -103,12 +70,6 @@ int test_compiler()
 	{
 		switch(GLM_COMPILER)
 		{
-		case GLM_COMPILER_CLANG32:
-			std::printf("Clang 3.2\n");
-			break;
-		case GLM_COMPILER_CLANG33:
-			std::printf("Clang 3.3\n");
-			break;
 		case GLM_COMPILER_CLANG34:
 			std::printf("Clang 3.4\n");
 			break;
@@ -145,23 +106,17 @@ int test_compiler()
 	{
 		switch(GLM_COMPILER)
 		{
-		case GLM_COMPILER_INTEL12:
-			std::printf("ICC 12\n");
-			break;
-		case GLM_COMPILER_INTEL12_1:
-			std::printf("ICC 12.1\n");
-			break;
-		case GLM_COMPILER_INTEL13:
-			std::printf("ICC 13\n");
-			break;
 		case GLM_COMPILER_INTEL14:
-			std::printf("ICC 14\n");
+			std::printf("ICC 14 - 2013 SP1\n");
 			break;
 		case GLM_COMPILER_INTEL15:
-			std::printf("ICC 15\n");
+			std::printf("ICC 15 - 2015\n");
 			break;
 		case GLM_COMPILER_INTEL16:
-			std::printf("ICC 16\n");
+			std::printf("ICC 16 - 2017\n");
+			break;
+		case GLM_COMPILER_INTEL17:
+			std::printf("ICC 17 - 20XX\n");
 			break;
 		default:
 			std::printf("Intel compiler version not detected\n");
