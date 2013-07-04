--- mozilla/toolkit/components/osfile/osfile_unix_allthreads.jsm.orig	2013-05-11 21:19:53.000000000 +0200
+++ mozilla/toolkit/components/osfile/osfile_unix_allthreads.jsm	2013-06-02 17:15:05.000000000 +0200
@@ -40,7 +40,7 @@ if (typeof Components != "undefined") {
   // Open libc
   let libc;
   let libc_candidates =  [ "libSystem.B.dylib",
-                           "libc.so.6",
+                           "libc.so.7",
                            "libc.so" ];
   for (let i = 0; i < libc_candidates.length; ++i) {
     try {
