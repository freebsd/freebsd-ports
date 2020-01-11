--- postfix_mta_sts_resolver/daemon.py.orig	2020-01-11 21:18:26 UTC
+++ postfix_mta_sts_resolver/daemon.py
@@ -7,7 +7,6 @@ import logging
 import signal
 from functools import partial
 
-from sdnotify import SystemdNotifier
 from . import utils
 from . import defaults
 from .responder import STSSocketmapResponder
@@ -72,11 +71,8 @@ async def amain(cfg, loop):  # pragma: no cover
     sig_handler = partial(exit_handler, exit_event)
     signal.signal(signal.SIGTERM, sig_handler)
     signal.signal(signal.SIGINT, sig_handler)
-    notifier = await loop.run_in_executor(None, SystemdNotifier)
-    await loop.run_in_executor(None, notifier.notify, "READY=1")
     await exit_event.wait()
     logger.debug("Eventloop interrupted. Shutting down server...")
-    await loop.run_in_executor(None, notifier.notify, "STOPPING=1")
     beat.cancel()
     await responder.stop()
 
