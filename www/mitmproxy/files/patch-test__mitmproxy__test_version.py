--- test/mitmproxy/test_version.py.orig	2021-09-28 16:43:29 UTC
+++ test/mitmproxy/test_version.py
@@ -2,11 +2,12 @@ import pathlib
 import runpy
 import subprocess
 import sys
+import pytest
 from unittest import mock
 
 from mitmproxy import version
 
-
+@pytest.mark.skip
 def test_version(capsys):
     here = pathlib.Path(__file__).absolute().parent
     version_file = here / ".." / ".." / "mitmproxy" / "version.py"
@@ -16,6 +17,7 @@ def test_version(capsys):
     assert stdout.strip() == version.VERSION
 
 
+@pytest.mark.skip
 def test_get_version():
     version.VERSION = "3.0.0rc2"
 
