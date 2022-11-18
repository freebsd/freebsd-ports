From: =?UTF-8?q?Timoth=C3=A9e=20Mazzucotelli?= <pawamoy@pm.me>
Date: Wed, 2 Feb 2022 12:27:27 +0100
Subject: [PATCH] refactor: Support Jinja2 3.1

Issue #360: https://github.com/mkdocstrings/mkdocstrings/issues/360
PR #361: https://github.com/mkdocstrings/mkdocstrings/issues/361

--- src/mkdocstrings/loggers.py.orig	2021-12-27 17:59:33 UTC
+++ src/mkdocstrings/loggers.py
@@ -4,10 +4,14 @@ from typing import Any, Callable, Optional, Tuple
 from pathlib import Path
 from typing import Any, Callable, Optional, Tuple
 
-from jinja2 import contextfunction
 from jinja2.runtime import Context
 from mkdocs.utils import warning_filter
 
+try:
+    from jinja2 import pass_context
+except ImportError:  # TODO: remove once Jinja2 < 3.1 is dropped
+    from jinja2 import contextfunction as pass_context  # noqa: WPS440
+
 TEMPLATES_DIR = Path(__file__).parent / "templates"
 
 
@@ -71,7 +75,7 @@ def get_template_logger_function(logger_func: Callable
         A function.
     """
 
-    @contextfunction
+    @pass_context
     def wrapper(context: Context, msg: Optional[str] = None) -> str:
         """Log a message.
 
