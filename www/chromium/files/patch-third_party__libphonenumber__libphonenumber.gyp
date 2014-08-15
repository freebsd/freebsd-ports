--- ./third_party/libphonenumber/libphonenumber.gyp.orig	2014-08-12 21:02:49.000000000 +0200
+++ ./third_party/libphonenumber/libphonenumber.gyp	2014-08-13 09:56:58.000000000 +0200
@@ -11,6 +11,7 @@
       # generated protocol headers to be available with "phonenumbers" include
       # path, e.g. #include "phonenumbers/foo.pb.h".
       '<(SHARED_INTERMEDIATE_DIR)/protoc_out/third_party/libphonenumber',
+      '<(prefix_dir)/include',
     ],
     'defines': [
       'I18N_PHONENUMBERS_USE_ICU_REGEXP=1',
