--- third_party/libphonenumber/libphonenumber.gyp.orig	2016-05-11 19:02:34 UTC
+++ third_party/libphonenumber/libphonenumber.gyp
@@ -11,6 +11,7 @@
       # generated protocol headers to be available with "phonenumbers" include
       # path, e.g. #include "phonenumbers/foo.pb.h".
       '<(SHARED_INTERMEDIATE_DIR)/protoc_out/third_party/libphonenumber',
+      '<(prefix_dir)/include',
     ],
     'defines': [
       'I18N_PHONENUMBERS_USE_ICU_REGEXP=1',
