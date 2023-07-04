--- src/SALOMEDSImpl/SALOMEDSImpl_Study.cxx.orig	2023-07-03 21:36:43 UTC
+++ src/SALOMEDSImpl/SALOMEDSImpl_Study.cxx
@@ -212,7 +212,7 @@ bool SALOMEDSImpl_Study::Open(const std::string& aUrl)
     isASCII = true;
     char* aResultPath = HDFascii::ConvertFromASCIIToHDF(aUrl.c_str());
     if ( !aResultPath )
-      return NULL;
+      return false;
     aC_HDFUrl = new char[strlen(aResultPath) + 19];
     sprintf(aC_HDFUrl, "%shdf_from_ascii.hdf", aResultPath);
     delete [] (aResultPath);
@@ -234,7 +234,7 @@ bool SALOMEDSImpl_Study::Open(const std::string& aUrl)
     sprintf(eStr,"Can't open file %s",aUrl.c_str());
     delete [] eStr;
     _errorCode = std::string(eStr);
-    return NULL;
+    return false;
   }
 
   // Assign the value of the URL in the study object
