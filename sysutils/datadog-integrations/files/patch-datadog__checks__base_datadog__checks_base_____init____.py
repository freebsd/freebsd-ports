--- datadog_checks_base/datadog_checks/base/__init__.py.orig	2020-10-29 10:27:27 UTC
+++ datadog_checks_base/datadog_checks/base/__init__.py
@@ -3,7 +3,6 @@
 # Licensed under a 3-clause BSD style license (see LICENSE)
 from .__about__ import __version__
 from .checks import AgentCheck
-from .checks.openmetrics import OpenMetricsBaseCheck
 from .config import is_affirmative
 from .errors import ConfigurationError
 from .utils.common import ensure_bytes, ensure_unicode, to_native_string, to_string
@@ -24,7 +23,6 @@ __all__ = [
     '__version__',
     'AgentCheck',
     'KubeLeaderElectionBaseCheck',
-    'OpenMetricsBaseCheck',
     'PDHBaseCheck',
     'ConfigurationError',
     'ensure_bytes',
