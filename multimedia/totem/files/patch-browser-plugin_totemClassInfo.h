--- browser-plugin/totemClassInfo.h.orig	2007-08-09 17:32:58.000000000 +0000
+++ browser-plugin/totemClassInfo.h	2007-08-09 17:55:50.000000000 +0000
@@ -47,10 +47,10 @@
 NS_IMETHODIMP _class::GetClassDescription(char * *aClassDescription)\
 {\
   *aClassDescription = static_cast<char*>(\
-				       nsMemory::Clone (_description,\
-						        sizeof (_description)));\
+				       nsMemory::Alloc (sizeof (_description) + 1));\
   if (!*aClassDescription)\
     return NS_ERROR_OUT_OF_MEMORY;\
+  strcpy(*aClassDescription, _description);\
 \
   return NS_OK;\
 }\
@@ -59,10 +59,10 @@
 NS_IMETHODIMP _class::GetClassID(nsCID * *aClassID)\
 {\
   *aClassID = static_cast<nsCID*>(\
-			      nsMemory::Clone (&_cid,\
-					       sizeof (nsCID*)));\
+			      nsMemory::Alloc (sizeof (nsCID*) + 1));\
   if (!*aClassID)\
     return NS_ERROR_OUT_OF_MEMORY;\
+  memcpy(*aClassID, &_cid, sizeof (nsCID*));\
 \
   return NS_OK;\
 }\
@@ -99,13 +99,12 @@
 
 #define TOTEM_CLASSINFO_ENTRY(_i, _interface)\
   (*array)[_i] = static_cast<nsIID*>(\
-                                 nsMemory::Clone(&NS_GET_IID(_interface),\
-                                                 sizeof(nsIID)));\
+                                 nsMemory::Alloc(sizeof(nsIID) + 1));\
   if (!(*array)[_i]) {\
     NS_FREE_XPCOM_ALLOCATED_POINTER_ARRAY (_i, *array);\
     return NS_ERROR_OUT_OF_MEMORY;\
-  }
-
+  }\
+  memcpy((*array)[_i], &NS_GET_IID(_interface), sizeof(nsIID));
 
 #define TOTEM_CLASSINFO_END \
   return NS_OK;\
