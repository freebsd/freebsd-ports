--- src/rendercv/cli/error_handler.py.orig	2025-12-20 00:46:25 UTC
+++ src/rendercv/cli/error_handler.py
@@ -8,7 +8,7 @@ from rendercv.exception import RenderCVUserError
 from rendercv.exception import RenderCVUserError
 
 
-def handle_user_errors[T, **P](function: Callable[P, None]) -> Callable[P, None]:
+def handle_user_errors(function):
     """Decorator that catches user errors and displays friendly messages without stack traces.
 
     Why:
@@ -33,7 +33,7 @@ def handle_user_errors[T, **P](function: Callable[P, N
     """
 
     @functools.wraps(function)
-    def wrapper(*args: P.args, **kwargs: P.kwargs) -> None:
+    def wrapper(*args, **kwargs) -> None:
         try:
             return function(*args, **kwargs)
         except RenderCVUserError as e:
