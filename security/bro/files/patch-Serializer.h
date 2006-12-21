--- Serializer.h.orig	Thu Dec 21 13:24:28 2006
+++ Serializer.h	Thu Dec 21 13:24:45 2006
@@ -82,8 +82,8 @@
 	void StartSerialization();
 	bool EndSerialization();
 
-	bool Serializer::UnserializeID();
-	bool Serializer::UnserializeEvent();
+	bool UnserializeID();
+	bool UnserializeEvent();
 
 	SerializationFormat* format;
 
