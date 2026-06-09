--- src/yubal_api/domain/types.py.orig	2026-06-08 18:55:40 UTC
+++ src/yubal_api/domain/types.py
@@ -2,7 +2,8 @@ from datetime import datetime
 
 from collections.abc import Callable
 from datetime import datetime
+from typing import TypeAlias
 
 # Callable type aliases for dependency injection
-type Clock = Callable[[], datetime]
-type IdGenerator = Callable[[], str]
+Clock: TypeAlias = Callable[[], datetime]
+IdGenerator: TypeAlias = Callable[[], str]
