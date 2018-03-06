Convert coreutils commands to FreeBSD equivalents

--- test/test_digest.py.orig	2018-03-06 14:23:55 UTC
+++ test/test_digest.py
@@ -45,7 +45,7 @@ class TestDigest(unittest.TestCase):
         #
         # We want to read the reference result from the subprocess as text
         # not binary, thus universal_newlines must be True.
-        proc = subprocess.Popen([ref_cmd, in_filename], stdout=subprocess.PIPE,
+        proc = subprocess.Popen([ref_cmd, '-r', in_filename], stdout=subprocess.PIPE,
                                 universal_newlines=True)
         stdout, stderr = proc.communicate()
         reference_digest = stdout.split()[0]
@@ -103,16 +103,16 @@ class TestDigest(unittest.TestCase):
                              (hash_oid_name, reference_digest, test_digest))
 
     def test_md5(self):
-        self.do_test('md5', 'md5sum', nss.md5_digest, nss.SEC_OID_MD5)
+        self.do_test('md5', 'md5', nss.md5_digest, nss.SEC_OID_MD5)
 
     def test_sha1(self):
-        self.do_test('sha1', 'sha1sum', nss.sha1_digest, nss.SEC_OID_SHA1)
+        self.do_test('sha1', 'sha1', nss.sha1_digest, nss.SEC_OID_SHA1)
 
     def test_sha256(self):
-        self.do_test('sha256', 'sha256sum', nss.sha256_digest, nss.SEC_OID_SHA256)
+        self.do_test('sha256', 'sha256', nss.sha256_digest, nss.SEC_OID_SHA256)
 
     def test_sha512(self):
-        self.do_test('sha512', 'sha512sum', nss.sha512_digest, nss.SEC_OID_SHA512)
+        self.do_test('sha512', 'sha512', nss.sha512_digest, nss.SEC_OID_SHA512)
 
 
 #-------------------------------------------------------------------------------
