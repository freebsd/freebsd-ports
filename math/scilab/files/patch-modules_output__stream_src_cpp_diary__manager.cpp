--- modules/output_stream/src/cpp/diary_manager.cpp.orig	2015-03-31 09:31:36 UTC
+++ modules/output_stream/src/cpp/diary_manager.cpp
@@ -61,7 +61,7 @@ wchar_t **getDiaryFilenames(int *array_s
     if (SCIDIARY)
     {
         std::wstring * wstringFilenames = SCIDIARY->getFilenames(array_size);
-        if (array_size > 0)
+        if (*array_size > 0)
         {
             wchar_t **wcFilenames = (wchar_t **) MALLOC (sizeof(wchar_t*) * (*array_size));
             for (int i = 0; i < *array_size; i++)
