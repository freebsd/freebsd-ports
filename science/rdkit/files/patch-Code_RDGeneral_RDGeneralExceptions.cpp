-- Fix cross-DLL Boost.Python exception translation on FreeBSD.
-- Move exported exception-class destructors out-of-line so the Itanium ABI
-- emits a single typeinfo/vtable instance per class in its owning shared
-- library. Without this each shared module has its own local typeinfo copy
-- and catch-by-derived-type in Python exception translators fails.

--- Code/RDGeneral/RDGeneralExceptions.cpp.orig	2026-08-28 02:56:41 UTC
+++ Code/RDGeneral/RDGeneralExceptions.cpp
@@ -16,3 +16,12 @@
 #include "BadFileException.h"
 #include "Exceptions.h"
 #include "FileParseException.h"
+
+IndexErrorException::~IndexErrorException() noexcept = default;
+ValueErrorException::~ValueErrorException() noexcept = default;
+KeyErrorException::~KeyErrorException() noexcept = default;
+
+namespace RDKit {
+BadFileException::~BadFileException() noexcept = default;
+FileParseException::~FileParseException() noexcept = default;
+}  // namespace RDKit
