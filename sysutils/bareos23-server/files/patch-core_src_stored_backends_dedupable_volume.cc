--- core/src/stored/backends/dedupable/volume.cc.orig	2025-09-18 21:46:06 UTC
+++ core/src/stored/backends/dedupable/volume.cc
@@ -228,8 +228,8 @@ data::data(open_context ctx, const config& conf)
 
   raii_fd bfd = OpenRelative(ctx, bf.relpath.c_str());
   raii_fd pfd = OpenRelative(ctx, pf.relpath.c_str());
-  blocks = decltype(blocks){ctx.read_only, bfd.fileno(), bf.End};
-  parts = decltype(parts){ctx.read_only, pfd.fileno(), pf.End};
+  blocks = decltype(blocks){ctx.read_only, bfd.fileno(), static_cast<size_t>(bf.End)};
+  parts = decltype(parts){ctx.read_only, pfd.fileno(), static_cast<size_t>(pf.End)};
   fds.emplace_back(std::move(bfd));
   fds.emplace_back(std::move(pfd));
 
