-- Generate C++ null pointer literals in mechanism headers.
-- Clang 21 rejects generated headers that use NULL without a defining include.
-- Needed for Arbor 0.12.2 local builds on FreeBSD; no upstream reference found.

--- modcc/printer/infoprinter.cpp.orig	2026-09-15 16:51:36 UTC
+++ modcc/printer/infoprinter.cpp
@@ -63,7 +63,7 @@ ARB_LIBMODCC_API std::string build_info_header(const M
     auto print_array_head = [&](char const * type, char const * name, auto size) {
         out << "    static " << type;
         if (size) out << " " << name << "[] = {";
-        else out << "* " << name << " = NULL;";
+        else out << "* " << name << " = nullptr;";
     };
     auto print_array_tail = [&](char const * type, char const * name, auto size) {
         if (size) out << " };";
