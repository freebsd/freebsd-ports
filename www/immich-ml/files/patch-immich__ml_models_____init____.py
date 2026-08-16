--- immich_ml/models/__init__.py.orig	2026-08-16 16:21:56 UTC
+++ immich_ml/models/__init__.py
@@ -3,8 +3,12 @@ from immich_ml.models.clip.visual import OpenClipVisua
 from immich_ml.models.base import InferenceModel
 from immich_ml.models.clip.textual import MClipTextualEncoder, OpenClipTextualEncoder
 from immich_ml.models.clip.visual import OpenClipVisualEncoder
-from immich_ml.models.ocr.detection import TextDetector
-from immich_ml.models.ocr.recognition import TextRecognizer
+try:
+    from immich_ml.models.ocr.detection import TextDetector
+    from immich_ml.models.ocr.recognition import TextRecognizer
+except ImportError:  # rapidocr has not been ported to FreeBSD yet
+    TextDetector = None  # type: ignore[assignment,misc]
+    TextRecognizer = None  # type: ignore[assignment,misc]
 from immich_ml.schemas import ModelSource, ModelTask, ModelType
 
 from .constants import get_model_source
@@ -31,9 +35,13 @@ def get_model_class(model_name: str, model_type: Model
             return FaceRecognizer
 
         case ModelSource.PADDLE, ModelType.DETECTION, ModelTask.OCR:
+            if TextDetector is None:
+                raise ValueError("OCR models require rapidocr, which is not available")
             return TextDetector
 
         case ModelSource.PADDLE, ModelType.RECOGNITION, ModelTask.OCR:
+            if TextRecognizer is None:
+                raise ValueError("OCR models require rapidocr, which is not available")
             return TextRecognizer
 
         case _:
