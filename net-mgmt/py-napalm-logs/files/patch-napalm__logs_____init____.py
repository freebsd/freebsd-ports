Description: Look up the version with importlib.metadata instead of
  pkg_resources.
Issue ID: https://github.com/napalm-automation/napalm-logs/issues/393
Changeset: https://github.com/napalm-automation/napalm-logs/pull/394 (open,
  not ours)
TODO: Drop when a release includes PR #394.

--- napalm_logs/__init__.py.orig	2022-11-08 13:33:16 UTC
+++ napalm_logs/__init__.py
@@ -5,7 +5,7 @@ napalm-logs package init
 from __future__ import absolute_import
 from __future__ import unicode_literals
 
-import pkg_resources
+import importlib.metadata
 import os
 
 # For metrics collection, the prometheus_client library
@@ -19,8 +19,8 @@ os.environ["prometheus_multiproc_dir"] =
 from napalm_logs.base import NapalmLogs  # noqa: E402
 
 try:
-    __version__ = pkg_resources.get_distribution("napalm-logs").version
-except pkg_resources.DistributionNotFound:
+    __version__ = importlib.metadata.version("napalm-logs")
+except importlib.metadata.PackageNotFoundError:
     __version__ = "Not installed"
 
 
