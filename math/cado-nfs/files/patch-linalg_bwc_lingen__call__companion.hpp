--- linalg/bwc/lingen_call_companion.hpp.orig	2024-04-08 11:23:28 UTC
+++ linalg/bwc/lingen_call_companion.hpp
@@ -177,7 +177,7 @@ namespace fmt {
     // c++-14 or later
     auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) { return ctx.begin(); }
     template <typename FormatContext>
-auto format(lingen_call_companion::key const & c, FormatContext& ctx) -> decltype(ctx.out()) {
+        auto format(lingen_call_companion::key const & c, FormatContext& ctx) const -> decltype(ctx.out()) {
             std::ostringstream os;
             os << c;
             return formatter<string_view>::format( string_view(os.str()), ctx);
