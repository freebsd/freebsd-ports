powerpc and i386 fix for:
undefined reference to `WTF::Optional<unsigned long>
JSC::parse<unsigned long>(char const*)'

Index: Source/JavaScriptCore/runtime/Options.cpp
--- Source/JavaScriptCore/runtime/Options.cpp.orig
+++ Source/JavaScriptCore/runtime/Options.cpp
@@ -91,7 +91,7 @@ std::optional<OptionsStorage::Unsigned> parse(const ch
     return std::nullopt;
 }
 
-#if CPU(ADDRESS64) || OS(DARWIN)
+#if CPU(ADDRESS64) || OS(DARWIN) || OS(OPENBSD)
 template<>
 std::optional<OptionsStorage::Size> parse(const char* string)
 {
@@ -100,7 +100,7 @@ std::optional<OptionsStorage::Size> parse(const char* 
         return value;
     return std::nullopt;
 }
-#endif // CPU(ADDRESS64) || OS(DARWIN)
+#endif // CPU(ADDRESS64) || OS(DARWIN) || OS(OPENBSD)
 
 template<>
 std::optional<OptionsStorage::Double> parse(const char* string)
