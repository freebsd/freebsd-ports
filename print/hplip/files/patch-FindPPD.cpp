--- FindPPD.cpp.orig	2022-02-23 07:41:04 UTC
+++ FindPPD.cpp
@@ -15,7 +15,7 @@ unsigned char  CreateModelDict(MODEL_DICT_MAP &model_d
 
     unsigned char family_ppd = 0;
     fstream file_pointer;
-    file_pointer.open("/usr/share/hplip/data/models/models.dat", fstream::in);
+    file_pointer.open("/usr/local/share/hplip/data/models/models.dat", fstream::in);
 
     if(!file_pointer)
     {
