From: "James R. Barlow" <james@purplerock.ca>
Date: Mon, 4 Jan 2021 20:21:51 -0800
Subject: [PATCH] Fix externalize_inline_images for qpdf 10.1.0

Obtained from:

https://github.com/pikepdf/pikepdf/commit/7ac9b058104219b26747f3fc9761ac6b3c037402.patch

--- src/qpdf/page.cpp.orig	2020-09-09 22:57:09 UTC
+++ src/qpdf/page.cpp
@@ -79,7 +79,10 @@ void init_page(py::module& m)
         .def("_get_mediabox", &QPDFPageObjectHelper::getMediaBox)
         .def("_get_cropbox", &QPDFPageObjectHelper::getCropBox)
         .def("_get_trimbox", &QPDFPageObjectHelper::getTrimBox)
-        .def("externalize_inline_images", &QPDFPageObjectHelper::externalizeInlineImages,
+        .def("externalize_inline_images",
+            [](QPDFPageObjectHelper &poh, size_t min_size = 0) {
+                return poh.externalizeInlineImages(min_size);
+            },
             py::arg("min_size") = 0,
             R"~~~(
                 Convert inlines image to normal (external) images.
