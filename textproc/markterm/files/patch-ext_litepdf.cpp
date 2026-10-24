--- ext/litepdf.cpp.orig	2026-10-20 14:15:24 UTC
+++ ext/litepdf.cpp
@@ -968,6 +968,7 @@ class PdfContainer : public litehtml::document_container
     HPDF_Doc pdf = nullptr;
     std::string base_dir;
     litehtml::pixel_t content_width = 0;
+    litehtml::pixel_t viewport_height = 1000000; // height used to resolve CSS fixed/percent positioning
     bool kdp_embed = false;      // kdp mode: base-14 fonts become embedded TrueTypes
     bool mirror_headers = false; // mirrored running heads: swap header/footer sides on verso pages
     bool dpi_audit = false;      // warn when raster images render below 300 DPI
@@ -2249,7 +2250,7 @@ class PdfContainer : public litehtml::document_container
         viewport.x = 0;
         viewport.y = 0;
         viewport.width = content_width;
-        viewport.height = 1000000;
+        viewport.height = viewport_height;
     }
 
     litehtml::element::ptr create_element(const char*, const litehtml::string_map&,
@@ -3055,6 +3056,18 @@ static int render_pdf(const char* html, const char* css, float page_width_mm, fl
         content_width = page_width - margin_gutter_v - std::max(margin_left_v, margin_right_v);
     }
     container.content_width = content_width;
+    // CSS `position: fixed` anchors to the viewport, which for a print
+    // renderer is one page's content area. Give litehtml a viewport as
+    // tall as that area so `bottom: 0` means "content bottom" (and
+    // `100vh`/percent heights resolve against a page) instead of an
+    // unbounded canvas that pushed such boxes a million pixels away.
+    // Pageless mode keeps the unbounded default (its single page grows
+    // to fit, so there is no fixed page height).
+    if (!single_page)
+    {
+        float content_height = page_height - margin_top_v - margin_bottom_v;
+        container.viewport_height = (litehtml::pixel_t)std::round(content_height);
+    }
 
     // Note: render() returns the root's natural width; the laid-out
     // document height is what matters for pagination. A litehtml throw
@@ -3302,6 +3315,12 @@ static int render_pdf(const char* html, const char* css, float page_width_mm, fl
     }
 
     if (getenv("LITEPDF_DEBUG")) { for (auto& w : windows) std::fprintf(stderr, "window %.1f..%.1f\n", w.first, w.second); }
+    // Fixed-positioned boxes (position: fixed) anchor to the viewport,
+    // which markpdf sizes to one page of content. Collect them once after
+    // layout so each page can draw them at its own bottom edge.
+    litehtml::position::vector fixed_boxes;
+    doc->get_fixed_boxes(fixed_boxes);
+    bool has_fixed = !fixed_boxes.empty();
     DrawContext context;
     context.wide_tables = &container.wide_tables;
     container.active_context = &context;
@@ -3541,6 +3560,49 @@ static int render_pdf(const char* html, const char* css, float page_width_mm, fl
             // device space and get scaled explicitly instead.
             HPDF_Page_GRestore(page);
         }
+        // Fixed-positioned boxes draw once per page, anchored to the page
+        // bottom (the viewport is one page tall). They live outside the
+        // window clip, so they are drawn in their own pass: y_offset 0
+        // maps the content origin to this page's top, and the clip spans
+        // the full content height instead of the window slice.
+        if (has_fixed && !window.blank)
+        {
+            HPDF_Page_GSave(page);
+            int prev_y_offset = (int)context.y_offset;
+            int prev_window_first = (int)context.window_first;
+            int prev_window_second = (int)context.window_second;
+            bool prev_paginated = context.paginated;
+            context.y_offset = 0;
+            context.window_first = 0;
+            context.window_second = content_height;
+            context.paginated = false;
+            HPDF_Page_Rectangle(page, left_margin, page_height - margin_top_v - content_height,
+                                content_width, content_height);
+            HPDF_Page_Clip(page);
+            HPDF_Page_EndPath(page);
+            litehtml::position fixed_clip(0, 0, (int)std::ceil(content_width), (int)std::ceil(content_height));
+            try
+            {
+                doc->draw_fixed(reinterpret_cast<litehtml::uint_ptr>(&context), &fixed_clip);
+            }
+            catch (const std::exception& error)
+            {
+                std::snprintf(errbuf, errbuf_len, "fixed draw failed: %s", error.what());
+                HPDF_Free(pdf);
+                return -1;
+            }
+            catch (...)
+            {
+                std::snprintf(errbuf, errbuf_len, "fixed draw failed");
+                HPDF_Free(pdf);
+                return -1;
+            }
+            context.y_offset = prev_y_offset;
+            context.window_first = prev_window_first;
+            context.window_second = prev_window_second;
+            context.paginated = prev_paginated;
+            HPDF_Page_GRestore(page);
+        }
         // Header/footer go in the margins, outside the window clip; a
         // pageless document has no pages to decorate, and a blank
         // filler page stays blank.
