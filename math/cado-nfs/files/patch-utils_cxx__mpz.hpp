--- utils/cxx_mpz.hpp.orig	2024-04-08 11:23:28 UTC
+++ utils/cxx_mpz.hpp
@@ -234,9 +234,9 @@ namespace fmt {
     // only allow {} for formatting. No :, no :x, etc. It could be nice
     // to allow them, though. Note that this should be constexpr with
     // c++-14 or later
-    auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) { return ctx.begin(); }
+    auto parse(format_parse_context& ctx) const -> decltype(ctx.begin()) { return ctx.begin(); }
     template <typename FormatContext>
-auto format(cxx_mpz const & c, FormatContext& ctx) -> decltype(ctx.out()) {
+    auto format(cxx_mpz const & c, FormatContext& ctx) const -> decltype(ctx.out()) {
             std::ostringstream os;
             os << c;
             return formatter<string_view>::format( string_view(os.str()), ctx);
