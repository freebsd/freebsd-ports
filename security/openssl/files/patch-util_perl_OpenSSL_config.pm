--- util/perl/OpenSSL/config.pm.orig	2022-04-12 16:34:06 UTC
+++ util/perl/OpenSSL/config.pm
@@ -747,8 +747,9 @@ EOF
                                     disable => [ 'sse2' ] } ],
       [ 'alpha.*-.*-.*bsd.*',     { target => "BSD-generic64",
                                     defines => [ 'L_ENDIAN' ] } ],
-      [ 'powerpc64-.*-.*bsd.*',   { target => "BSD-generic64",
-                                    defines => [ 'B_ENDIAN' ] } ],
+      [ 'powerpc-.*-.*bsd.*',     { target => "BSD-ppc" } ],
+      [ 'powerpc64-.*-.*bsd.*',   { target => "BSD-ppc64" } ],
+      [ 'powerpc64le-.*-.*bsd.*', { target => "BSD-ppc64le" } ],
       [ 'riscv64-.*-.*bsd.*',     { target => "BSD-riscv64" } ],
       [ 'sparc64-.*-.*bsd.*',     { target => "BSD-sparc64" } ],
       [ 'ia64-.*-.*bsd.*',        { target => "BSD-ia64" } ],
