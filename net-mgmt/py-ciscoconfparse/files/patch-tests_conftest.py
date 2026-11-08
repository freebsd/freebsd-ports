* Enable test suite compatibility with py-pytest 9+

--- tests/conftest.py.orig	2026-08-21 16:06:50 UTC
+++ tests/conftest.py
@@ -1424,10 +1424,6 @@ def parse_n01_factory(request):
     yield parse_n01_factory


-@pytest.mark.skipif(sys.version_info[0] >= 3, reason="No Python3 MockSSH support")
-@pytest.mark.skipif(
-    "windows" in platform.system().lower(), reason="No Windows MockSSH support"
-)
 @pytest.fixture(scope="session")
 def cisco_sshd_mocked(request):
     """Mock Cisco IOS SSH"""
