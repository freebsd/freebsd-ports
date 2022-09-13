--- tensorflow/tools/pip_package/setup.py.orig	2022-09-07 19:29:52 UTC
+++ tensorflow/tools/pip_package/setup.py
@@ -77,13 +77,12 @@ REQUIRED_PACKAGES = [
     'astunparse >= 1.6.0',
     # TODO(b/187981032): remove the constraint for 2.0 once the incompatibile
     # issue is resolved.
-    'flatbuffers >= 1.12, <2',
+    'flatbuffers',
     # TODO(b/213222745) gast versions above 0.4.0 break TF's tests
-    'gast >= 0.2.1, <= 0.4.0',
+    'gast',
     'google_pasta >= 0.1.1',
     'h5py >= 2.9.0',
-    'keras_preprocessing >= 1.1.1',  # 1.1.0 needs tensorflow==1.7
-    'libclang >= 13.0.0',
+    'keras_preprocessing >= 1.1.0',  # 1.1.0 needs tensorflow==1.7
     'numpy >= 1.20',
     'opt_einsum >= 2.3.2',
     'packaging',
@@ -94,13 +93,12 @@ REQUIRED_PACKAGES = [
     # See also: https://github.com/protocolbuffers/protobuf/issues/9954
     # See also: https://github.com/tensorflow/tensorflow/issues/56077
     # This is a temporary patch for now, to patch previous TF releases.
-    'protobuf >= 3.9.2, < 3.20',
+    'protobuf',
     'setuptools',
     'six >= 1.12.0',
     'termcolor >= 1.1.0',
     'typing_extensions >= 3.6.6',
     'wrapt >= 1.11.0',
-    'tensorflow-io-gcs-filesystem >= 0.23.1',
     # grpcio does not build correctly on big-endian machines due to lack of
     # BoringSSL support.
     # See https://github.com/tensorflow/tensorflow/issues/17882.
