--- spf_engine/milter_spf.py.orig	2020-02-26 02:21:41 UTC
+++ spf_engine/milter_spf.py
@@ -37,7 +37,6 @@ import spf_engine.policydspfsupp as config
 from spf_engine.util import drop_privileges
 from spf_engine.policydspfsupp import _setExceptHook
 from spf_engine.util import write_pid
-from spf_engine.util import own_socketfile
 from spf_engine.util import fold
 
 __version__ = "2.9.2"
