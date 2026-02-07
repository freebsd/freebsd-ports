https://gitlab.com/sequoia-pgp/sequoia-cert-store/-/merge_requests/89

--- cargo-crates/sequoia-cert-store-0.7.0/src/store/certd.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/sequoia-cert-store-0.7.0/src/store/certd.rs
@@ -988,7 +988,7 @@ -- Record the schema version.
 );
 
 -- Record the schema version.
-INSERT OR IGNORE INTO version VALUES (0, 1, \"sequoia cert cache v1\");
+INSERT OR IGNORE INTO version VALUES (0, 1, 'sequoia cert cache v1');
 
 -- Tag of the certd directory to quickly detect whether the db is stale.
 DROP TABLE IF EXISTS certd_tag;
