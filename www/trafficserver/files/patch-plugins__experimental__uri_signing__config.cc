--- plugins/experimental/uri_signing/config.cc.orig	2024-11-12 19:49:58 UTC
+++ plugins/experimental/uri_signing/config.cc
@@ -104,7 +104,7 @@ config_new(size_t n)
     free(cfg);
     return nullptr;
   }
-  PluginDebug("Created table with size %d", cfg->issuers->size);
+  PluginDebug("Created table with size %d", n * 2);
 
   cfg->jwkis    = static_cast<cjose_jwk_t ***>(malloc((n + 1) * sizeof *cfg->jwkis));
   cfg->jwkis[n] = nullptr;
@@ -269,7 +269,7 @@ read_config_from_json(json_t *const issuer_json)
         *jwkis = nullptr;
         goto cfg_fail;
       }
-      PluginDebug("Created table with size %d", cfg->issuers->size);
+      PluginDebug("Created table");
 
       const char *renewal_kid      = nullptr;
       json_t     *renewal_kid_json = json_object_get(jwks, "renewal_kid");
@@ -295,7 +295,7 @@ read_config_from_json(json_t *const issuer_json)
 
       size_t        jwks_ct = json_array_size(key_ary);
       cjose_jwk_t **jwks = *jwkis++ = static_cast<cjose_jwk_t **>(malloc((jwks_ct + 1) * sizeof *jwks));
-      PluginDebug("Created table with size %d", cfg->issuers->size);
+      PluginDebug("Created table");
       ENTRY *dummy;
       if (!hsearch_r(((ENTRY){*issuer, jwks}), ENTER, &dummy, cfg->issuers)) {
         PluginDebug("Failed to store keys for issuer %s", *issuer);
