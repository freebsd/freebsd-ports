-- Use the nanoseconds= argument of uuid_utils.compat.uuid7().
-- uuid-utils 1.x removed the timestamp=/nanos= arguments; upstream caps uuid-utils<1.0
-- but the port ignores upper bounds and ships uuid-utils 1.x.

--- langchain_core/utils/uuid.py.orig	2026-11-07 00:00:45 UTC
+++ langchain_core/utils/uuid.py
@@ -50,8 +50,7 @@ def uuid7(nanoseconds: int | None = None) -> UUID:
     # For now, just delegate to the uuid_utils implementation
     if nanoseconds is None:
         return _uuid_utils_uuid7()
-    seconds, nanos = _to_timestamp_and_nanos(nanoseconds)
-    return _uuid_utils_uuid7(timestamp=seconds, nanos=nanos)
+    return _uuid_utils_uuid7(nanoseconds=nanoseconds)
 
 
 __all__ = ["uuid7"]
