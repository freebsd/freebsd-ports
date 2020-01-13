# pytest_namespace() was removed in 4.x
# See: https://docs.pytest.org/en/latest/deprecations.html#pytest-namespacehttps://docs.pytest.org/en/latest/deprecations.html#pytest-namespace
# TODO: Upstream

--- tests/indirect_parametrize.py.orig	2014-01-21 19:06:03 UTC
+++ tests/indirect_parametrize.py
@@ -112,6 +112,7 @@ def pytest_configure(config):
         "argument list and keyword argument dictionary) based on the received "
         "input data. For more detailed information see the "
         "indirect_parametrize pytest plugin implementation module.")
+    pytest.indirect_parametrize = indirect_parametrize
 
 
 def pytest_generate_tests(metafunc):
@@ -123,8 +124,3 @@ def pytest_generate_tests(metafunc):
         return
     args, kwargs = mark.args[0](*mark.args[1:], **mark.kwargs)
     metafunc.parametrize(*args, **kwargs)
-
-
-def pytest_namespace():
-    """pytest hook publishing references in the toplevel pytest namespace."""
-    return {'indirect_parametrize': indirect_parametrize}
