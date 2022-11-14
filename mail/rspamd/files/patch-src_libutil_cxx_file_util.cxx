diff --git a/src/libutil/cxx/file_util.cxx b/src/libutil/cxx/file_util.cxx
index e3b3a2605..4536fa97b 100644
--- src/libutil/cxx/file_util.cxx
+++ src/libutil/cxx/file_util.cxx
@@ -198,7 +198,7 @@ auto raii_mmaped_file::mmap_shared(raii_file &&file,
 	}
 	/* Update stat on file to ensure it is up-to-date */
 	file.update_stat();
-	map = mmap(nullptr, file.get_size() - offset, flags, MAP_SHARED, file.get_fd(), offset);
+	map = mmap(nullptr, (std::size_t)(file.get_size() - offset), flags, MAP_SHARED, file.get_fd(), offset);
 
 	if (map == MAP_FAILED) {
 		return tl::make_unexpected(error { fmt::format("cannot mmap file {}: {}",
@@ -206,7 +206,7 @@ auto raii_mmaped_file::mmap_shared(raii_file &&file,
 
 	}
 
-	return raii_mmaped_file{std::move(file), map,  file.get_size() - offset};
+	return raii_mmaped_file{std::move(file), map,  (std::size_t)(file.get_size() - offset)};
 }
 
 auto raii_mmaped_file::mmap_shared(const char *fname, int open_flags,
