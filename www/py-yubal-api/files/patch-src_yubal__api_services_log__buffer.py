--- src/yubal_api/services/log_buffer.py.orig	2026-06-08 20:18:05 UTC
+++ src/yubal_api/services/log_buffer.py
@@ -8,7 +8,7 @@ from datetime import datetime
 from collections.abc import AsyncIterator
 from contextlib import asynccontextmanager
 from datetime import datetime
-from typing import Any, ClassVar, override
+from typing import Any, ClassVar
 
 from yubal_api.schemas.logs import LogEntry, LogEntryType, LogStats
 
@@ -123,7 +123,6 @@ class BufferHandler(logging.Handler):
         super().__init__()
         self._buffer = buffer
 
-    @override
     def emit(self, record: logging.LogRecord) -> None:
         """Serialize log record to validated JSON and append to buffer."""
         try:
