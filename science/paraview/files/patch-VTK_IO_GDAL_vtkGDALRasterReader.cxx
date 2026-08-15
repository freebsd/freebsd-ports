--- VTK/IO/GDAL/vtkGDALRasterReader.cxx.orig	2026-05-22 16:18:17 UTC
+++ VTK/IO/GDAL/vtkGDALRasterReader.cxx
@@ -182,7 +182,7 @@ void vtkGDALRasterReader::vtkGDALRasterReaderInternal:
     this->Reader->DriverShortName = GDALGetDriverShortName(driver);
     this->Reader->DriverLongName = GDALGetDriverLongName(driver);
 
-    char** papszMetaData = GDALGetMetadata(this->GDALData, nullptr);
+    CSLConstList papszMetaData = GDALGetMetadata(this->GDALData, nullptr);
     if (CSLCount(papszMetaData) > 0)
     {
       for (int i = 0; papszMetaData[i] != nullptr; ++i)
@@ -882,7 +882,7 @@ std::vector<std::string> vtkGDALRasterReader::GetDomai
 {
   std::vector<std::string> domainMetaData;
 
-  char** papszMetadata = GDALGetMetadata(this->Impl->GDALData, domain.c_str());
+  CSLConstList papszMetadata = GDALGetMetadata(this->Impl->GDALData, domain.c_str());
 
   if (CSLCount(papszMetadata) > 0)
   {
