Python 3.12 introduced stricter bounds checking for the C-API buffer
protocol. In tests/t-idiomatic.py, the io.BytesIO buffer is preallocated
to 128 bytes to work around https://bugs.python.org/issue27261. However,
modern GnuPG signatures such as Ed25519 require at least 149 bytes.

Under Python <= 3.11, writing the 149-byte payload into the 128-byte
memory view was silently tolerated. Python 3.12 correctly catches the
truncation during op_sign() and aborts with ValueError.

This patch increases the preallocated test buffer size to 256 bytes,
ensuring enough capacity for the signature payload and allowing the
test suite to pass cleanly with Python 3.12.

--- tests/t-idiomatic.py.orig	2025-06-04 12:17:11 UTC
+++ tests/t-idiomatic.py
@@ -79,7 +79,7 @@ if sys.version_info[0] == 3:
     bio.truncate(1)
     if len(bio.getvalue()) != 1:
         # This version of Python is affected, preallocate buffer.
-        preallocate = 128 * b'\x00'
+        preallocate = 256 * b'\x00'
     else:
         preallocate = b''
 
