--- third_party/serf/select_openssl.gyp.orig	2017-06-08 22:22:39 UTC
+++ third_party/serf/select_openssl.gyp
@@ -42,15 +42,15 @@
           'type': 'none',
           'direct_dependent_settings': {
             'cflags': [
-              '<!@(pkg-config --cflags openssl)',
+              '<!@(if [ -e %%LOCALBASE%%/libdata/pkgconfig/openssl.pc ]; then pkg-config --cflags openssl; else echo "-I/usr/include -DTSI_OPENSSL_ALPN_SUPPORT=0"; fi)',
             ],
           },
           'link_settings': {
             'ldflags': [
-              '<!@(pkg-config --libs-only-L --libs-only-other openssl)',
+              '<!@(if [ -e %%LOCALBASE%%/libdata/pkgconfig/openssl.pc ]; then pkg-config --libs openssl; else echo "-L/usr/lib -lssl -lcrypto"; fi)',
             ],
             'libraries': [
-              '<!@(pkg-config --libs-only-l openssl)',
+              '<!@(if [ -e %%LOCALBASE%%/libdata/pkgconfig/openssl.pc ]; then pkg-config --libs openssl; else echo "-L/usr/lib -lssl -lcrypto"; fi)',
             ],
           },
         },
