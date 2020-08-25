--- go.mod.orig	2020-08-25 17:39:09 UTC
+++ go.mod
@@ -6,8 +6,6 @@ replace github.com/hashicorp/vault/api => ./api
 
 replace github.com/hashicorp/vault/sdk => ./sdk
 
-replace github.com/hashicorp/vault-plugin-auth-gcp => github.com/hashicorp/vault-plugin-auth-gcpent v0.0.0-20200721115240-07ff53341dfe
-
 require (
 	cloud.google.com/go v0.56.0
 	cloud.google.com/go/spanner v1.5.1
@@ -71,7 +69,7 @@ require (
 	github.com/hashicorp/vault-plugin-auth-azure v0.5.6
 	github.com/hashicorp/vault-plugin-auth-centrify v0.5.5
 	github.com/hashicorp/vault-plugin-auth-cf v0.5.4
-	github.com/hashicorp/vault-plugin-auth-gcp v0.7.0
+        github.com/hashicorp/vault-plugin-auth-gcp v0.7.1-0.20200721115240-07ff53341dfe
 	github.com/hashicorp/vault-plugin-auth-jwt v0.7.3
 	github.com/hashicorp/vault-plugin-auth-kerberos v0.1.6
 	github.com/hashicorp/vault-plugin-auth-kubernetes v0.7.0
