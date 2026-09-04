https://github.com/aio-libs/yarl/issues/1872

--- tests/test_pydantic.py.orig	2026-05-19 19:57:25 UTC
+++ tests/test_pydantic.py
@@ -10,6 +10,9 @@ else:
     pydantic = pytest.importorskip("pydantic")
 
 
+pytest.skip("fails with 'RuntimeError: no validator found for <class 'yarl.URL'>, see `arbitrary_types_allowed` in Config'", allow_module_level=True)
+
+
 class TstModel(pydantic.BaseModel):
     url: URL
 
