--- third_party/serf/select_openssl.gyp.orig	2017-10-04 20:20:10 UTC
+++ third_party/serf/select_openssl.gyp
@@ -47,10 +47,10 @@
           },
           'link_settings': {
             'ldflags': [
-              '<!@(pkg-config --libs-only-L --libs-only-other openssl)',
+              '<!@(pkg-config --libs openssl)',
             ],
             'libraries': [
-              '<!@(pkg-config --libs-only-l openssl)',
+              '<!@(pkg-config --libs openssl)',
             ],
           },
         },
