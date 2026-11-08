-- Honour DEDUP_DATA here too, the log cannot go next to the sources.

--- src/util/log.py.orig	2026-11-07 09:38:16 UTC
+++ src/util/log.py
@@ -8,7 +8,7 @@ KeepDays = 3
 LogLevel = logging.INFO
 KeepDays = 3
 
-log_dir = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(__file__))), 'data', 'logs')
+log_dir = os.path.join(os.getenv('DEDUP_DATA', os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(__file__))), 'data')), 'logs')
 os.makedirs(log_dir, exist_ok=True)
 
 log_file = os.path.join(log_dir, 'deduper.log')
