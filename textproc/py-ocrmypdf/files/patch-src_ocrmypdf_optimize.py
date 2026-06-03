From: "James R. Barlow" <james@purplerock.ca>
Date: Sun, 9 Nov 2025 15:43:36 -0800
Subject: [PATCH] Work around Ghostscript 10.6.0 JPEG encoding issue by forcing
 optimization.

Not an ideal fix, but it improves an issue affecting numerous users.

Fixes 1585.

Obtained from:

https://github.com/ocrmypdf/OCRmyPDF/commit/f4c6c8121ba8178ff3a1cb8f70037bbc3a31391b.patch

--- src/ocrmypdf/optimize.py.orig	2020-02-02 00:00:00 UTC
+++ src/ocrmypdf/optimize.py
@@ -17,6 +17,7 @@ import img2pdf
 from zlib import compress
 
 import img2pdf
+from packaging.version import Version
 from pikepdf import (
     Dictionary,
     Name,
@@ -32,7 +33,7 @@ from ocrmypdf._concurrent import Executor, SerialExecu
 from PIL import Image
 
 from ocrmypdf._concurrent import Executor, SerialExecutor
-from ocrmypdf._exec import jbig2enc, pngquant
+from ocrmypdf._exec import ghostscript, jbig2enc, pngquant
 from ocrmypdf._jobcontext import PdfContext
 from ocrmypdf._progressbar import ProgressBar
 from ocrmypdf.exceptions import OutputFileAccessError
@@ -189,6 +190,16 @@ def extract_image_jbig2(
     return None
 
 
+def _should_optimize_jpeg(options, filtdp):
+    if options.optimize >= 2:
+        return True
+    if options.optimize < 2 and ghostscript.version() >= Version('10.6.0'):
+        # Ghostscript 10.6.0+ introduced some sort of JPEG encoding issue.
+        # To resolve this, re-optimize the JPEG anyway.
+        return True
+    return False
+
+
 def extract_image_generic(
     *, pdf: Pdf, root: Path, image: Stream, xref: Xref, options
 ) -> XrefExt | None:
@@ -202,15 +213,7 @@ def extract_image_generic(
     if pim.bits_per_component == 1:
         return None
 
-    if filtdp[0] == Name.DCTDecode and options.optimize >= 2:
-        # This is a simple heuristic derived from some training data, that has
-        # about a 70% chance of guessing whether the JPEG is high quality,
-        # and possibly recompressible, or not. The number itself doesn't mean
-        # anything.
-        # bytes_per_pixel = int(raw_jpeg.Length) / (w * h)
-        # jpeg_quality_estimate = 117.0 * (bytes_per_pixel ** 0.213)
-        # if jpeg_quality_estimate < 65:
-        #     return None
+    if filtdp[0] == Name.DCTDecode and _should_optimize_jpeg(options, filtdp):
         try:
             imgname = root / f'{xref:08d}'
             with imgname.open('wb') as f:
