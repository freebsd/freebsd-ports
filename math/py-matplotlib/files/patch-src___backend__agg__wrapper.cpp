--- src/_backend_agg_wrapper.cpp.orig	2026-03-06 16:43:44 UTC
+++ src/_backend_agg_wrapper.cpp
@@ -250,12 +250,12 @@ PYBIND11_MODULE(_backend_agg, m, py::mod_gil_not_used(
 
         .def_buffer([](RendererAgg *renderer) -> py::buffer_info {
             std::vector<py::ssize_t> shape {
-                renderer->get_height(),
-                renderer->get_width(),
+                static_cast<py::ssize_t>(renderer->get_height()),
+                static_cast<py::ssize_t>(renderer->get_width()),
                 4
             };
             std::vector<py::ssize_t> strides {
-                renderer->get_width() * 4,
+                static_cast<py::ssize_t>(renderer->get_width() * 4),
                 4,
                 1
             };
@@ -269,12 +269,12 @@ PYBIND11_MODULE(_backend_agg, m, py::mod_gil_not_used(
         .def("get_extents", &PyBufferRegion_get_extents)
         .def_buffer([](BufferRegion *buffer) -> py::buffer_info {
             std::vector<py::ssize_t> shape {
-                buffer->get_height(),
-                buffer->get_width(),
+                static_cast<py::ssize_t>(buffer->get_height()),
+                static_cast<py::ssize_t>(buffer->get_width()),
                 4
             };
             std::vector<py::ssize_t> strides {
-                buffer->get_width() * 4,
+                static_cast<py::ssize_t>(buffer->get_width() * 4),
                 4,
                 1
             };
