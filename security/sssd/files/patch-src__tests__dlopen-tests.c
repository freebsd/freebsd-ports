diff --git src/tests/dlopen-tests.c src/tests/dlopen-tests.c
index 9a5d3597f..4b469726b 100644
--- src/tests/dlopen-tests.c
+++ src/tests/dlopen-tests.c
@@ -44,7 +44,7 @@ struct so {
     { "libipa_hbac.so", { LIBPFX"libipa_hbac.so", NULL } },
     { "libsss_idmap.so", { LIBPFX"libsss_idmap.so", NULL } },
     { "libsss_nss_idmap.so", { LIBPFX"libsss_nss_idmap.so", NULL } },
-    { "libnss_sss.so", { LIBPFX"libnss_sss.so", NULL } },
+    { "nss_sss.so", { LIBPFX"nss_sss.so", NULL } },
     { "libsss_certmap.so", { LIBPFX"libsss_certmap.so", NULL } },
     { "pam_sss.so", { LIBPFX"pam_sss.so", NULL } },
 #ifdef BUILD_LIBWBCLIENT
@@ -82,8 +82,6 @@ struct so {
     { "libsss_util.so", { LIBPFX"libsss_util.so", NULL } },
     { "libsss_simple.so", { LIBPFX"libdlopen_test_providers.so",
                             LIBPFX"libsss_simple.so", NULL } },
-    { "libsss_files.so", { LIBPFX"libdlopen_test_providers.so",
-                           LIBPFX"libsss_files.so", NULL } },
 #ifdef BUILD_SAMBA
     { "libsss_ad.so", { LIBPFX"libdlopen_test_providers.so",
                         LIBPFX"libsss_ad.so", NULL } },
