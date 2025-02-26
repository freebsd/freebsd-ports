--- src/librekey/key_store_g10.cpp.orig	2024-05-03 10:03:14 UTC
+++ src/librekey/key_store_g10.cpp
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2017-2022, [Ribose Inc](https://www.ribose.com).
+ * Copyright (c) 2017-2024, [Ribose Inc](https://www.ribose.com).
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
@@ -312,12 +312,12 @@ read_curve(const sexp_list_t *list, const std::string 
 
     const auto &bytes = data->get_string();
     pgp_curve_t curve = static_cast<pgp_curve_t>(
-      id_str_pair::lookup(g10_curve_aliases, data->get_string(), PGP_CURVE_UNKNOWN));
+      id_str_pair::lookup(g10_curve_aliases, (const char *) bytes.data(), PGP_CURVE_UNKNOWN));
     if (curve != PGP_CURVE_UNKNOWN) {
         key.curve = curve;
         return true;
     }
-    RNP_LOG("Unknown curve: %.*s", (int) bytes.size(), (char *) bytes.data());
+    RNP_LOG("Unknown curve: %.*s", (int) bytes.size(), (const char *) bytes.data());
     return false;
 }
 
@@ -806,7 +806,7 @@ g23_parse_seckey(pgp_key_pkt_t &seckey,
 
     auto &           alg_bt = alg_s_exp->sexp_string_at(0)->get_string();
     pgp_pubkey_alg_t alg = static_cast<pgp_pubkey_alg_t>(
-      id_str_pair::lookup(g10_alg_aliases, alg_bt.c_str(), PGP_PKA_NOTHING));
+      id_str_pair::lookup(g10_alg_aliases, (const char *) alg_bt.data(), PGP_PKA_NOTHING));
     if (alg == PGP_PKA_NOTHING) {
         RNP_LOG(
           "Unsupported algorithm: '%.*s'", (int) alg_bt.size(), (const char *) alg_bt.data());
