Workaround for OpenSSL 1.0.2t/u to handle unnamed but really named curves

PR #5362

Obtained from:
https://github.com/pyca/cryptography/commit/241f845071a8747d0986ed60575e28840f096b79

--- src/cryptography/hazmat/backends/openssl/ec.py.orig	2020-04-22 22:26:51 UTC
+++ src/cryptography/hazmat/backends/openssl/ec.py
@@ -42,7 +42,7 @@ def _ec_key_curve_sn(backend, ec_key):
     # explicitly encoded a curve with the same parameters as a named curve.
     # Don't do that.
     if (
-        backend._lib.CRYPTOGRAPHY_OPENSSL_110_OR_GREATER and
+        backend._lib.CRYPTOGRAPHY_OPENSSL_102U_OR_GREATER and
         backend._lib.EC_GROUP_get_asn1_flag(group) == 0
     ):
         raise NotImplementedError(
@@ -195,12 +195,7 @@ class _EllipticCurvePrivateKey(object):
         self._backend.openssl_assert(group != self._backend._ffi.NULL)
 
         curve_nid = self._backend._lib.EC_GROUP_get_curve_name(group)
-
-        public_ec_key = self._backend._lib.EC_KEY_new_by_curve_name(curve_nid)
-        self._backend.openssl_assert(public_ec_key != self._backend._ffi.NULL)
-        public_ec_key = self._backend._ffi.gc(
-            public_ec_key, self._backend._lib.EC_KEY_free
-        )
+        public_ec_key = self._backend._ec_key_new_by_curve_nid(curve_nid)
 
         point = self._backend._lib.EC_KEY_get0_public_key(self._ec_key)
         self._backend.openssl_assert(point != self._backend._ffi.NULL)
