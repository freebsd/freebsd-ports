--- OrthancServer/FromDcmtkBridge.cpp.orig	2016-07-20 11:36:11 UTC
+++ OrthancServer/FromDcmtkBridge.cpp
@@ -197,7 +197,7 @@ namespace Orthanc
       LoadEmbeddedDictionary(*locker, EmbeddedResources::DICTIONARY_DICOM);
       LoadEmbeddedDictionary(*locker, EmbeddedResources::DICTIONARY_PRIVATE);
 
-#elif defined(__linux__) || defined(__FreeBSD_kernel__)
+#elif defined(__linux__) || defined(__FreeBSD__)
       std::string path = DCMTK_DICTIONARY_DIR;
 
       const char* env = std::getenv(DCM_DICT_ENVIRONMENT_VARIABLE);
