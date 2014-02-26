--- ./contrib/olsr/face.hh.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./contrib/olsr/face.hh	2014-02-26 21:17:13.000000000 +0000
@@ -291,8 +291,10 @@
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
