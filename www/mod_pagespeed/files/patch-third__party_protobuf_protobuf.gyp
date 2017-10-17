--- third_party/protobuf/protobuf.gyp.orig	2017-06-08 22:22:39 UTC
+++ third_party/protobuf/protobuf.gyp
@@ -518,6 +518,7 @@
         {
           'target_name': 'protobuf_lite',
           'type': 'none',
+          'toolsets': ['host','target'],
           'direct_dependent_settings': {
             'cflags': [
               # Use full protobuf, because vanilla protobuf doesn't have
@@ -529,15 +530,17 @@
 
               # This macro must be defined to suppress the use
               # of dynamic_cast<>, which requires RTTI.
-              'GOOGLE_PROTOBUF_NO_RTTI',
-              'GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER',
+              #'GOOGLE_PROTOBUF_NO_RTTI',
+              #'GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER',
             ],
           },
           'link_settings': {
             # Use full protobuf, because vanilla protobuf doesn't have
             # our custom patch to retain unknown fields in lite mode.
+            # Formerly this --> '<!@(pkg-config --libs-only-L --libs-only-other protobuf)',
+            # But it seems to be incorrect for grpc, so I changed it...
             'ldflags': [
-              '<!@(pkg-config --libs-only-L --libs-only-other protobuf)',
+              '<!@(pkg-config --libs protobuf)',
             ],
             'libraries': [
               '<!@(pkg-config --libs-only-l protobuf)',
@@ -545,6 +548,40 @@
           },
         },
         {
+          'target_name': 'protoc_lib',
+          'type': 'none',
+          'toolsets': ['host'],
+          'link_settings': {
+           'ldflags': [
+             '-lprotoc',
+           ],
+          },
+          'dependencies': [
+            'protobuf_lite',
+          ],
+        },
+        {
+          'target_name': 'protobuf_message_differencer',
+          'type': 'none',
+          'toolsets': ['target'],
+          'dependencies': [
+            'protobuf_lite',
+          ],
+        },
+        {
+          'target_name': 'protobuf_full_do_not_use',
+          'type': 'none',
+          'toolsets': ['host','target'],
+          'link_settings': {
+           'ldflags': [
+             '-lprotoc',
+           ],
+          },
+          'dependencies': [
+            'protobuf_lite',
+          ],
+        },
+        {
           'target_name': 'protoc',
           'type': 'none',
           'toolsets': ['host', 'target'],
