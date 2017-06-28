--- common.gypi.orig	2017-06-28 05:52:55 UTC
+++ common.gypi
@@ -407,9 +407,6 @@
         'libraries': [ '-lelf' ],
       }],
       ['OS=="freebsd"', {
-        # Use this flag because on FreeBSD std::pairs copy constructor is non-trivial
-        # https://lists.freebsd.org/pipermail/freebsd-toolchain/2016-March/002094.html
-        'cflags': [ '-D_LIBCPP_TRIVIAL_PAIR_COPY_CTOR=1' ],
         'ldflags': [
           '-Wl,--export-dynamic',
         ],
