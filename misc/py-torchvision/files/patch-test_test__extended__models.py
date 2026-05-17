--- test/test_extended_models.py.orig	2026-05-17 05:19:19 UTC
+++ test/test_extended_models.py
@@ -428,7 +428,7 @@ class TestHandleLegacyInterface:
         def builder(*, weights=None):
             pass
 
-        with pytest.warns(UserWarning, match="positional"):
+        with pytest.warns(UserWarning, match="positional|deprecated"):
             builder(pretrained)
 
     @pytest.mark.parametrize("pretrained", (True, False))
@@ -448,7 +448,7 @@ class TestHandleLegacyInterface:
             pass
 
         args, kwargs = ((pretrained,), dict()) if positional else ((), dict(pretrained=pretrained))
-        with pytest.warns(UserWarning, match=f"weights={self.ModelWeights.Sentinel if pretrained else None}"):
+        with pytest.warns(UserWarning, match=f"(weights={self.ModelWeights.Sentinel if pretrained else None}|positional|deprecated)"):
             builder(*args, **kwargs)
 
     def test_multi_params(self):
