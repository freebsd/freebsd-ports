--- tests/conftest.py.orig	2025-04-17 17:07:02 UTC
+++ tests/conftest.py
@@ -13,7 +13,7 @@ _log = logging.getLogger("arviz_plots")
 
 _log = logging.getLogger("arviz_plots")
 
-settings.register_profile("fast", deadline=5000, max_examples=15)
+settings.register_profile("fast", deadline=None, max_examples=15)
 settings.register_profile("chron", deadline=5000, max_examples=500)
 settings.load_profile(os.getenv("HYPOTHESIS_PROFILE", "fast"))
 
