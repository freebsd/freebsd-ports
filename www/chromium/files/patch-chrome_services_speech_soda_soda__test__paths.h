--- chrome/services/speech/soda/soda_test_paths.h.orig	2021-09-14 01:51:52 UTC
+++ chrome/services/speech/soda/soda_test_paths.h
@@ -34,7 +34,7 @@ constexpr base::FilePath::CharType kSodaResourcePath[]
 constexpr base::FilePath::CharType kSodaTestBinaryRelativePath[] =
     FILE_PATH_LITERAL("SODA_for_testing.dll");
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 
 constexpr base::FilePath::CharType kSodaResourcePath[] =
     FILE_PATH_LITERAL("third_party/soda/resources");
