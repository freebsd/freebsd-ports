--- contrib/olsr/face.hh.orig	2012-01-11 17:56:10 UTC
+++ contrib/olsr/face.hh
@@ -291,8 +291,10 @@ class Face {
      */
     void originate_hello();
 
-  private:
     Olsr&		_olsr;
+
+  private:
+    // Olsr&		_olsr;
     FaceManager&	_fm;
     Neighborhood*	_nh;
     MessageDecoder&	_md;
