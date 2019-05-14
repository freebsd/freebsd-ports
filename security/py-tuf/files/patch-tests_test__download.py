# https://github.com/theupdateframework/tuf/pull/781#discussion_r221880421
# Need to import sys to use it

--- tests/test_download.py.orig	2019-05-14 10:30:26 UTC
+++ tests/test_download.py
@@ -36,6 +36,7 @@ import logging
 import os
 import random
 import subprocess
+import sys
 import time
 import unittest
 
