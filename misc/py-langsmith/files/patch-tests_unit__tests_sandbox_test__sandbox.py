-- Call request.read() before accessing request.content in sandbox write tests.
-- Multipart form uploads create streaming requests in httpx, and accessing
-- .content without calling .read() first raises httpx.RequestNotRead.
--- tests/unit_tests/sandbox/test_sandbox.py.orig	2026-06-29 17:31:20 UTC
+++ tests/unit_tests/sandbox/test_sandbox.py
@@ -401,6 +401,7 @@ class TestSandboxWrite:
 
         # Verify request is multipart form
         request = httpx_mock.get_request()
+        request.read()
         assert b"hello world" in request.content
         content_type = request.headers.get("content-type", "")
         assert content_type.startswith("multipart/form-data")
@@ -421,6 +422,7 @@ class TestSandboxWrite:
 
         # Verify request is multipart form with binary content
         request = httpx_mock.get_request()
+        request.read()
         assert binary_data in request.content
         content_type = request.headers.get("content-type", "")
         assert content_type.startswith("multipart/form-data")
