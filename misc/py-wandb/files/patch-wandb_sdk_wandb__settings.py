-- Wrap sentry_sdk import in _aws_lambda with try/except to handle the case
-- where sentry_sdk's import chain fails due to incompatible combinations of
-- installed packages (e.g., eventlet + trio raises NotImplementedError).
-- Without this, wandb.init() crashes when WANDB_ERROR_REPORTING=false and
-- both eventlet and trio are installed in the Python environment.
--- wandb/sdk/wandb_settings.py.orig	2026-04-28 04:23:53 UTC
+++ wandb/sdk/wandb_settings.py
@@ -1537,9 +1537,12 @@ class Settings(BaseModel, validate_assignment=True):
     @property
     def _aws_lambda(self) -> bool:
         """Check if we are running in a lambda environment."""
-        from sentry_sdk.integrations.aws_lambda import (  # type: ignore[import-not-found]
-            get_lambda_bootstrap,
-        )
+        try:
+            from sentry_sdk.integrations.aws_lambda import (  # type: ignore[import-not-found]
+                get_lambda_bootstrap,
+            )
+        except Exception:
+            return False
 
         lambda_bootstrap = get_lambda_bootstrap()
         return not (
