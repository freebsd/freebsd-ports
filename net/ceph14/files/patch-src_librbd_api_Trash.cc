diff --git src/librbd/api/Trash.cc src/librbd/api/Trash.cc
index 52f79632d5..3d539ab1e2 100644
--- src/librbd/api/Trash.cc
+++ src/librbd/api/Trash.cc
@@ -24,7 +24,6 @@
 #include <json_spirit/json_spirit.h>
 #include "librbd/journal/DisabledPolicy.h"
 #include "librbd/image/ListWatchersRequest.h"
-#include <experimental/map>
 
 #define dout_subsys ceph_subsys_rbd
 #undef dout_prefix
@@ -124,48 +123,6 @@ int enable_mirroring(IoCtx &io_ctx, const std::string &image_id) {
   return 0;
 }
 
-int list_trash_image_specs(
-    librados::IoCtx &io_ctx,
-    std::map<std::string, cls::rbd::TrashImageSpec>* trash_image_specs,
-    bool exclude_user_remove_source) {
-  CephContext *cct((CephContext *)io_ctx.cct());
-  ldout(cct, 20) << "list_trash_image_specs " << &io_ctx << dendl;
-
-  bool more_entries;
-  uint32_t max_read = 1024;
-  std::string last_read;
-  do {
-    std::map<string, cls::rbd::TrashImageSpec> trash_entries;
-    int r = cls_client::trash_list(&io_ctx, last_read, max_read,
-                                   &trash_entries);
-    if (r < 0 && r != -ENOENT) {
-      lderr(cct) << "error listing rbd trash entries: " << cpp_strerror(r)
-                 << dendl;
-      return r;
-    } else if (r == -ENOENT) {
-      break;
-    }
-
-    if (trash_entries.empty()) {
-      break;
-    }
-
-    for (const auto &entry : trash_entries) {
-      if (exclude_user_remove_source &&
-          entry.second.source == cls::rbd::TRASH_IMAGE_SOURCE_REMOVING) {
-        continue;
-      }
-
-      trash_image_specs->insert({entry.first, entry.second});
-    }
-
-    last_read = trash_entries.rbegin()->first;
-    more_entries = (trash_entries.size() >= max_read);
-  } while (more_entries);
-
-  return 0;
-}
-
 } // anonymous namespace
 
 template <typename I>
@@ -281,37 +238,15 @@ int Trash<I>::move(librados::IoCtx &io_ctx, rbd_trash_image_source_t source,
       return -EOPNOTSUPP;
     }
 
-    // search for an interrupted trash move request
-    std::map<std::string, cls::rbd::TrashImageSpec> trash_image_specs;
-    int r = list_trash_image_specs(io_ctx, &trash_image_specs, true);
-    if (r < 0) {
-      return r;
-    }
-
-    std::experimental::erase_if(
-      trash_image_specs, [image_name](const auto& pair) {
-        const auto& spec = pair.second;
-        return (spec.source != cls::rbd::TRASH_IMAGE_SOURCE_USER ||
-                spec.state != cls::rbd::TRASH_IMAGE_STATE_MOVING ||
-                spec.name != image_name);
-      });
-    if (trash_image_specs.empty()) {
-      return -ENOENT;
-    }
-
-    image_id = trash_image_specs.begin()->first;
-    ldout(cct, 15) << "derived image id " << image_id << " from existing "
-                   << "trash entry" << dendl;
+    // image doesn't exist -- perhaps already in the trash since removing
+    // from the directory is the last step
+    return -ENOENT;
   } else if (r < 0) {
     lderr(cct) << "failed to retrieve image id: " << cpp_strerror(r) << dendl;
     return r;
   }
 
-  if (image_name.empty() || image_id.empty()) {
-    lderr(cct) << "invalid image name/id" << dendl;
-    return -EINVAL;
-  }
-
+  ceph_assert(!image_name.empty() && !image_id.empty());
   return Trash<I>::move(io_ctx, source, image_name, image_id, delay);
 }
 
@@ -342,23 +277,41 @@ template <typename I>
 int Trash<I>::list(IoCtx &io_ctx, vector<trash_image_info_t> &entries,
                    bool exclude_user_remove_source) {
   CephContext *cct((CephContext *)io_ctx.cct());
-  ldout(cct, 20) << __func__ << " " << &io_ctx << dendl;
+  ldout(cct, 20) << "trash_list " << &io_ctx << dendl;
 
-  std::map<std::string, cls::rbd::TrashImageSpec> trash_image_specs;
-  int r = list_trash_image_specs(io_ctx, &trash_image_specs,
-                                 exclude_user_remove_source);
-  if (r < 0) {
-    return r;
-  }
+  bool more_entries;
+  uint32_t max_read = 1024;
+  std::string last_read = "";
+  do {
+    map<string, cls::rbd::TrashImageSpec> trash_entries;
+    int r = cls_client::trash_list(&io_ctx, last_read, max_read,
+                                   &trash_entries);
+    if (r < 0 && r != -ENOENT) {
+      lderr(cct) << "error listing rbd trash entries: " << cpp_strerror(r)
+                 << dendl;
+      return r;
+    } else if (r == -ENOENT) {
+      break;
+    }
 
-  entries.reserve(trash_image_specs.size());
-  for (const auto& [image_id, spec] : trash_image_specs) {
-    rbd_trash_image_source_t source =
-        static_cast<rbd_trash_image_source_t>(spec.source);
-    entries.push_back({image_id, spec.name, source,
-                       spec.deletion_time.sec(),
-                       spec.deferment_end_time.sec()});
-  }
+    if (trash_entries.empty()) {
+      break;
+    }
+
+    for (const auto &entry : trash_entries) {
+      rbd_trash_image_source_t source =
+          static_cast<rbd_trash_image_source_t>(entry.second.source);
+      if (exclude_user_remove_source &&
+          source == RBD_TRASH_IMAGE_SOURCE_REMOVING) {
+        continue;
+      }
+      entries.push_back({entry.first, entry.second.name, source,
+                         entry.second.deletion_time.sec(),
+                         entry.second.deferment_end_time.sec()});
+    }
+    last_read = trash_entries.rbegin()->first;
+    more_entries = (trash_entries.size() >= max_read);
+  } while (more_entries);
 
   return 0;
 }
@@ -587,12 +540,8 @@ int Trash<I>::remove(IoCtx &io_ctx, const std::string &image_id, bool force,
     lderr(cct) << "error: deferment time has not expired." << dendl;
     return -EPERM;
   }
-  if (trash_spec.state == cls::rbd::TRASH_IMAGE_STATE_MOVING) {
-    lderr(cct) << "error: image is pending moving to the trash."
-               << dendl;
-    return -EUCLEAN;
-  } else if (trash_spec.state != cls::rbd::TRASH_IMAGE_STATE_NORMAL &&
-             trash_spec.state != cls::rbd::TRASH_IMAGE_STATE_REMOVING) {
+  if (trash_spec.state != cls::rbd::TRASH_IMAGE_STATE_NORMAL &&
+      trash_spec.state != cls::rbd::TRASH_IMAGE_STATE_REMOVING) {
     lderr(cct) << "error: image is pending restoration." << dendl;
     return -EBUSY;
   }
@@ -750,3 +699,4 @@ int Trash<I>::restore(librados::IoCtx &io_ctx,
 } // namespace librbd
 
 template class librbd::api::Trash<librbd::ImageCtx>;
+
