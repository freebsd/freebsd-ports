--- crypto/ec/ec_asn1.c.orig	2015-02-10 14:54:46 UTC
+++ crypto/ec/ec_asn1.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: ec_asn1.c,v 1.11 2015/02/10 04:01:26 jsing Exp $ */
+/* $OpenBSD: ec_asn1.c,v 1.12 2015/02/10 05:43:09 jsing Exp $ */
 /*
  * Written by Nils Larsch for the OpenSSL project.
  */
@@ -999,19 +999,19 @@ d2i_ECPKParameters(EC_GROUP ** a, const 
 
 	if ((params = d2i_ECPKPARAMETERS(NULL, in, len)) == NULL) {
 		ECerr(EC_F_D2I_ECPKPARAMETERS, EC_R_D2I_ECPKPARAMETERS_FAILURE);
-		ECPKPARAMETERS_free(params);
-		return NULL;
+		goto err;
 	}
 	if ((group = ec_asn1_pkparameters2group(params)) == NULL) {
 		ECerr(EC_F_D2I_ECPKPARAMETERS, EC_R_PKPARAMETERS2GROUP_FAILURE);
-		ECPKPARAMETERS_free(params);
-		return NULL;
+		goto err;
 	}
-	if (a && *a)
+
+	if (a != NULL) {
 		EC_GROUP_clear_free(*a);
-	if (a)
 		*a = group;
+	}
 
+err:
 	ECPKPARAMETERS_free(params);
 	return (group);
 }
@@ -1039,7 +1039,6 @@ i2d_ECPKParameters(const EC_GROUP * a, u
 EC_KEY *
 d2i_ECPrivateKey(EC_KEY ** a, const unsigned char **in, long len)
 {
-	int ok = 0;
 	EC_KEY *ret = NULL;
 	EC_PRIVATEKEY *priv_key = NULL;
 
@@ -1054,12 +1053,9 @@ d2i_ECPrivateKey(EC_KEY ** a, const unsi
 	}
 	if (a == NULL || *a == NULL) {
 		if ((ret = EC_KEY_new()) == NULL) {
-			ECerr(EC_F_D2I_ECPRIVATEKEY,
-			    ERR_R_MALLOC_FAILURE);
+			ECerr(EC_F_D2I_ECPRIVATEKEY, ERR_R_MALLOC_FAILURE);
 			goto err;
 		}
-		if (a)
-			*a = ret;
 	} else
 		ret = *a;
 
@@ -1109,17 +1105,19 @@ d2i_ECPrivateKey(EC_KEY ** a, const unsi
 			goto err;
 		}
 	}
-	ok = 1;
+
+	EC_PRIVATEKEY_free(priv_key);
+	if (a != NULL)
+		*a = ret;
+	return (ret);
+
 err:
-	if (!ok) {
-		if (ret)
-			EC_KEY_free(ret);
-		ret = NULL;
-	}
+	if (a == NULL || *a != ret)
+		EC_KEY_free(ret);
 	if (priv_key)
 		EC_PRIVATEKEY_free(priv_key);
 
-	return (ret);
+	return (NULL);
 }
 
 int 
@@ -1232,8 +1230,6 @@ d2i_ECParameters(EC_KEY ** a, const unsi
 			ECerr(EC_F_D2I_ECPARAMETERS, ERR_R_MALLOC_FAILURE);
 			return NULL;
 		}
-		if (a)
-			*a = ret;
 	} else
 		ret = *a;
 
@@ -1241,6 +1237,9 @@ d2i_ECParameters(EC_KEY ** a, const unsi
 		ECerr(EC_F_D2I_ECPARAMETERS, ERR_R_EC_LIB);
 		return NULL;
 	}
+
+	if (a != NULL)
+		*a = ret;
 	return ret;
 }
 
