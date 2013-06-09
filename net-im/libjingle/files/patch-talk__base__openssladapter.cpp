--- talk/base/openssladapter.cc.orig
+++ talk/base/openssladapter.cc
@@ -641,7 +641,11 @@
     int extension_nid = OBJ_obj2nid(X509_EXTENSION_get_object(extension));
 
     if (extension_nid == NID_subject_alt_name) {
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+      const X509V3_EXT_METHOD* meth = X509V3_EXT_get(extension);
+#else
       X509V3_EXT_METHOD* meth = X509V3_EXT_get(extension);
+#endif
       if (!meth)
         break;
 
