--- src/binarycookies/_deserialize.py.orig	2025-04-08 19:50:17 UTC
+++ src/binarycookies/_deserialize.py
@@ -1,6 +1,7 @@
 from datetime import datetime, timezone
 from io import BytesIO
 from struct import unpack
+from sys import maxsize
 from typing import BinaryIO, List, Union
 
 from binarycookies.models import (
@@ -28,7 +29,9 @@ def interpret_flag(flags: int) -> Flag:
 
 def mac_epoch_to_date(epoch: int) -> datetime:
     """Converts a mac epoch time to a datetime object."""
-    return datetime.fromtimestamp(epoch + 978307200, tz=timezone.utc)
+    unix_epoch = epoch + 978307200
+    if unix_epoch > maxsize: unix_epoch = maxsize
+    return datetime.fromtimestamp(unix_epoch, tz=timezone.utc)
 
 
 def read_string(data: BytesIO, size: int) -> str:
