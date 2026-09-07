-- Fix build with newer pybind11/Imath by avoiding member function pointer
-- bindings that trigger template deduction failures due to IMATH_HOSTDEVICE
-- attributes on the member functions.
-- Reference: local poudriere build failure for 0.18.1 on FreeBSD 15-amd64.
-- Upstreamed: https://github.com/AcademySoftwareFoundation/OpenTimelineIO/issues/2037

--- src/py-opentimelineio/opentimelineio-bindings/otio_imath.cpp.orig
+++ src/py-opentimelineio/opentimelineio-bindings/otio_imath.cpp
@@ -76,14 +76,30 @@
         .def("cross", [](IMATH_NAMESPACE::V2d* v, IMATH_NAMESPACE::V2d const & v2) {
                 return v->cross(v2);
             })
-        .def("length", &IMATH_NAMESPACE::V2d::length)
-        .def("length2", &IMATH_NAMESPACE::V2d::length2)
-        .def("normalize", &IMATH_NAMESPACE::V2d::normalize)
-        .def("normalizeExc", &IMATH_NAMESPACE::V2d::normalizeExc)
-        .def("normalizeNonNull", &IMATH_NAMESPACE::V2d::normalizeNonNull)
-        .def("normalized", &IMATH_NAMESPACE::V2d::normalized)
-        .def("normalizedExc", &IMATH_NAMESPACE::V2d::normalizedExc)
-        .def("normalizedNonNull", &IMATH_NAMESPACE::V2d::normalizedNonNull)
+        .def("length", [](IMATH_NAMESPACE::V2d const& v) {
+                return v.length();
+            })
+        .def("length2", [](IMATH_NAMESPACE::V2d const& v) {
+                return v.length2();
+            })
+        .def("normalize", [](IMATH_NAMESPACE::V2d& v) {
+                return v.normalize();
+            })
+        .def("normalizeExc", [](IMATH_NAMESPACE::V2d& v) {
+                return v.normalizeExc();
+            })
+        .def("normalizeNonNull", [](IMATH_NAMESPACE::V2d& v) {
+                return v.normalizeNonNull();
+            })
+        .def("normalized", [](IMATH_NAMESPACE::V2d const& v) {
+                return v.normalized();
+            })
+        .def("normalizedExc", [](IMATH_NAMESPACE::V2d const& v) {
+                return v.normalizedExc();
+            })
+        .def("normalizedNonNull", [](IMATH_NAMESPACE::V2d const& v) {
+                return v.normalizedNonNull();
+            })
         .def_static("baseTypeLowest", []() {
                 return IMATH_NAMESPACE::V2d::baseTypeLowest();
             })
@@ -112,7 +128,9 @@
         .def("__ne__", [](IMATH_NAMESPACE::Box2d lhs, py::object const& rhs) {
             return lhs != _type_checked<IMATH_NAMESPACE::Box2d>(rhs, "!=");
         })
-        .def("center", &IMATH_NAMESPACE::Box2d::center)
+        .def("center", [](IMATH_NAMESPACE::Box2d const& box) {
+                return box.center();
+            })
         .def("extendBy", [](IMATH_NAMESPACE::Box2d* box, IMATH_NAMESPACE::V2d const& point ) {
             return box->extendBy(point);
         })
