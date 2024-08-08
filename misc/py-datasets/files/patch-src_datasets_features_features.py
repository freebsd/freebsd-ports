--- src/datasets/features/features.py.orig	2024-08-05 18:52:07 UTC
+++ src/datasets/features/features.py
@@ -32,7 +32,6 @@ import pyarrow.types
 import pyarrow as pa
 import pyarrow.compute as pc
 import pyarrow.types
-import pyarrow_hotfix  # noqa: F401  # to fix vulnerability on pyarrow<14.0.1
 from pandas.api.extensions import ExtensionArray as PandasExtensionArray
 from pandas.api.extensions import ExtensionDtype as PandasExtensionDtype
 
