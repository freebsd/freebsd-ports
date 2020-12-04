Workaround for OpenSSL 1.0.2t/u to handle unnamed but really named curves

PR #5362

Obtained from:
https://github.com/pyca/cryptography/commit/241f845071a8747d0986ed60575e28840f096b79

--- src/cryptography/hazmat/backends/openssl/backend.py.orig	2020-04-22 22:27:48 UTC
+++ src/cryptography/hazmat/backends/openssl/backend.py
@@ -1515,8 +1515,19 @@ class Backend(object):
 
     def _ec_key_new_by_curve(self, curve):
         curve_nid = self._elliptic_curve_to_nid(curve)
+        return self._ec_key_new_by_curve_nid(curve_nid)
+
+    def _ec_key_new_by_curve_nid(self, curve_nid):
         ec_cdata = self._lib.EC_KEY_new_by_curve_name(curve_nid)
         self.openssl_assert(ec_cdata != self._ffi.NULL)
+        # Setting the ASN.1 flag to OPENSSL_EC_NAMED_CURVE is
+        # only necessary on OpenSSL 1.0.2t/u. Once we drop support for 1.0.2
+        # we can remove this as it's done automatically when getting an EC_KEY
+        # from new_by_curve_name
+        # CRYPTOGRAPHY_OPENSSL_102U_OR_GREATER
+        self._lib.EC_KEY_set_asn1_flag(
+            ec_cdata, backend._lib.OPENSSL_EC_NAMED_CURVE
+        )
         return self._ffi.gc(ec_cdata, self._lib.EC_KEY_free)
 
     def load_der_ocsp_request(self, data):
