--- datadog_checks_base/datadog_checks/base/types.py.orig	2020-10-29 10:23:04 UTC
+++ datadog_checks_base/datadog_checks/base/types.py
@@ -1,7 +1,8 @@
 # (C) Datadog, Inc. 2020-present
 # All rights reserved
 # Licensed under a 3-clause BSD style license (see LICENSE)
-from typing import Any, Dict, List, Literal, NamedTuple, Optional, Sequence, Tuple, TypedDict, Union
+from typing import Any, Dict, List, NamedTuple, Optional, Sequence, Tuple, Union
+from typing_extensions import Literal, TypedDict

 InitConfigType = Dict[str, Any]
 AgentConfigType = Dict[str, Any]
