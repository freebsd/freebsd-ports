--- third_party/pdfium/build/standalone.gypi.orig	2016-05-11 19:03:45 UTC
+++ third_party/pdfium/build/standalone.gypi
@@ -18,7 +18,7 @@
       'variables': {
         'variables': {
           'conditions': [
-            ['OS=="linux" or OS=="mac"', {
+            ['OS=="linux" or OS=="mac" or OS=="freebsd"', {
               # This handles the Unix platforms we generally deal with.
               # Anything else gets passed through, which probably won't work
               # very well; such hosts should pass an explicit target_arch
@@ -31,7 +31,7 @@
                                        s/aarch64/arm64/;\
                                        s/mips.*/mipsel/")',
             }, {
-              # OS!="linux" and OS!="mac"
+              # OS!="linux" and OS!="mac" and OS!="freebsd"
               'host_arch%': 'ia32',
             }],
           ],
@@ -264,7 +264,7 @@
       # means we have to turn off this warning (and be careful about how
       # object destruction happens in such cases).
       4611,
-
+}
       # TODO(thestig): These warnings are level 4. They will be slowly
       # removed as code is fixed.
       4100, # Unreferenced formal parameter
