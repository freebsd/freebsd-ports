--- tests/sieve/test_fb_root.cpp.orig	2024-04-08 11:23:28 UTC
+++ tests/sieve/test_fb_root.cpp
@@ -57,9 +57,9 @@ template <typename T> struct /* fmt:: */ formatter<fb_
     // only allow {} for formatting. No :, no :x, etc. It could be nice
     // to allow them, though. Note that this should be constexpr with
     // c++-14 or later
-    auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) { return ctx.begin(); }
+    constexpr auto parse(format_parse_context& ctx) const -> decltype(ctx.begin()) { return ctx.begin(); }
     template <typename FormatContext>
-        auto format(fb_root_p1_t<T> const & c, FormatContext& ctx) -> decltype(ctx.out()) {
+        auto format(fb_root_p1_t<T> const & c, FormatContext& ctx) const -> decltype(ctx.out()) {
             std::ostringstream os;
             os << c;
             return formatter<string_view>::format( string_view(os.str()), ctx);
@@ -70,9 +70,9 @@ template <> struct /* fmt:: */ formatter<qlattice_basi
     // only allow {} for formatting. No :, no :x, etc. It could be nice
     // to allow them, though. Note that this should be constexpr with
     // c++-14 or later
-    auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) { return ctx.begin(); }
+    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) { return ctx.begin(); }
     template <typename FormatContext>
-        auto format(qlattice_basis const & c, FormatContext& ctx) -> decltype(ctx.out()) {
+        auto format(qlattice_basis const & c, FormatContext& ctx) const -> decltype(ctx.out()) {
             std::ostringstream os;
             os << c;
             return formatter<string_view>::format( string_view(os.str()), ctx);
