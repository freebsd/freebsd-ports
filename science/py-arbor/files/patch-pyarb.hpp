--- pyarb.hpp.orig	2025-11-02 17:35:26 UTC
+++ pyarb.hpp
@@ -19,7 +19,7 @@ static_assert((PYBIND11_VERSION_HEX >= 0x02080100)
 #define PB11_ERR(M, m, p) "Required version of pybind11 is 2.8.1 <= version < 3.0.0 Found " mk_ver(M, m, p)
 static_assert((PYBIND11_VERSION_HEX >= 0x02080100)
               &&
-              (PYBIND11_VERSION_HEX  < 0x03000000),
+              (PYBIND11_VERSION_HEX  < 0x04000000),
               PB11_ERR(PYBIND11_VERSION_MAJOR, PYBIND11_VERSION_MINOR, PYBIND11_VERSION_PATCH));
 #undef PB11_ERR
 #undef mk_ver
