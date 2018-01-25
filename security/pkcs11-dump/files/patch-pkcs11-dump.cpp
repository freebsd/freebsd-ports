--- pkcs11-dump.cpp.orig	2018-01-23 10:46:55 UTC
+++ pkcs11-dump.cpp
@@ -1136,7 +1136,7 @@ Dump (
 		for (int j=0;attrdescAttributes[j].nId!=-1;j++) {
 			char Buffer[10*1024];
 			CK_ATTRIBUTE t[] = {
-				{attrdescAttributes[j].nId, Buffer, sizeof (Buffer)}
+				{(CK_ATTRIBUTE_TYPE)attrdescAttributes[j].nId, Buffer, sizeof (Buffer)}
 			};
 
 			if (
