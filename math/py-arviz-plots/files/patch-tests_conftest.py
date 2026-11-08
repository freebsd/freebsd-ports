-- Remove Hypothesis deadline to prevent spurious test failures on slow build machines.
--- tests/conftest.py.orig	2026-09-10 20:53:50 UTC
+++ tests/conftest.py
@@ -18,7 +18,7 @@ _log = logging.getLogger("arviz_plots")
 
 _log = logging.getLogger("arviz_plots")
 
-settings.register_profile("fast", deadline=2000, max_examples=15)
+settings.register_profile("fast", deadline=None, max_examples=15)
 settings.register_profile("chron", deadline=5000, max_examples=500)
 settings.load_profile(os.getenv("HYPOTHESIS_PROFILE", "fast"))
 
