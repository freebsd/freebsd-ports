-- Explicitly cast memcpy() arguments to void*/const void* when copying raw
-- bytes of the non-trivially-copyable `DoF` struct (it has a user-defined
-- copy constructor), since newer Clang (21.x, as used on current FreeBSD)
-- turns this into a hard error (-Werror,-Wnontrivial-memcall) instead of a
-- warning; the raw byte copy itself is safe/intentional since DoF is a
-- simple wrapper around a single uint64_t with no virtual members.
--- src/smith/numerics/functional/element_restriction.cpp.orig	2026-10-01 19:09:44 UTC
+++ src/smith/numerics/functional/element_restriction.cpp
@@ -280,7 +280,7 @@ axom::Array<DoF, 2, smith::detail::host_memory_space> 
   } else {
     uint64_t dofs_per_elem = elem_dofs.size() / n;
     axom::Array<DoF, 2, smith::detail::host_memory_space> output(n, dofs_per_elem);
-    std::memcpy(output.data(), elem_dofs.data(), sizeof(DoF) * n * dofs_per_elem);
+    std::memcpy(static_cast<void*>(output.data()), static_cast<const void*>(elem_dofs.data()), sizeof(DoF) * n * dofs_per_elem);
     return output;
   }
 }
@@ -346,7 +346,7 @@ axom::Array<DoF, 2, smith::detail::host_memory_space> 
   } else {
     uint64_t dofs_per_elem = elem_dofs.size() / n;
     axom::Array<DoF, 2, smith::detail::host_memory_space> output(n, dofs_per_elem);
-    std::memcpy(output.data(), elem_dofs.data(), sizeof(DoF) * n * dofs_per_elem);
+    std::memcpy(static_cast<void*>(output.data()), static_cast<const void*>(elem_dofs.data()), sizeof(DoF) * n * dofs_per_elem);
     return output;
   }
 }
@@ -461,7 +461,7 @@ axom::Array<DoF, 2, smith::detail::host_memory_space> 
   } else {
     uint64_t dofs_per_face = face_dofs.size() / n;
     axom::Array<DoF, 2, smith::detail::host_memory_space> output(n, dofs_per_face);
-    std::memcpy(output.data(), face_dofs.data(), sizeof(DoF) * n * dofs_per_face);
+    std::memcpy(static_cast<void*>(output.data()), static_cast<const void*>(face_dofs.data()), sizeof(DoF) * n * dofs_per_face);
     return output;
   }
 }
@@ -634,7 +634,7 @@ axom::Array<DoF, 2, smith::detail::host_memory_space> 
   } else {
     uint64_t dofs_per_face = face_dofs.size() / n;
     axom::Array<DoF, 2, smith::detail::host_memory_space> output(n, dofs_per_face);
-    std::memcpy(output.data(), face_dofs.data(), sizeof(DoF) * n * dofs_per_face);
+    std::memcpy(static_cast<void*>(output.data()), static_cast<const void*>(face_dofs.data()), sizeof(DoF) * n * dofs_per_face);
     return output;
   }
 }
