# Disable deadline on test_argument_ranges
# https://github.com/hynek/argon2_cffi/pull/52

--- tests/test_low_level.py.orig	2018-06-17 05:51:36 UTC
+++ tests/test_low_level.py
@@ -5,7 +5,7 @@ import os
 
 import pytest
 
-from hypothesis import assume, given
+from hypothesis import assume, given, settings
 from hypothesis import strategies as st
 
 from argon2.exceptions import (
@@ -253,6 +253,7 @@ class TestVerify(object):
     hash_len=st.integers(lib.ARGON2_MIN_OUTLEN, 513),
     salt_len=st.integers(lib.ARGON2_MIN_SALT_LENGTH, 513),
 )
+@settings(deadline=None)
 def test_argument_ranges(
     password, time_cost, parallelism, memory_cost, hash_len, salt_len
 ):
