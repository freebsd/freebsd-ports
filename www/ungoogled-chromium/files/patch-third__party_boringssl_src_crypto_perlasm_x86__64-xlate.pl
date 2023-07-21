--- third_party/boringssl/src/crypto/perlasm/x86_64-xlate.pl.orig	2023-07-21 09:49:17 UTC
+++ third_party/boringssl/src/crypto/perlasm/x86_64-xlate.pl
@@ -1510,6 +1510,21 @@ OPTION	DOTNAME
 ___
 }
 
+if ($nasm) {
+    print <<___;
+\%define _CET_ENDBR
+___
+} else {
+    print <<___;
+#if defined(__CET__)
+#include <cet.h>
+#else
+#define _CET_ENDBR
+#endif
+
+___
+}
+
 if ($gas) {
     my $target;
     if ($elf) {
