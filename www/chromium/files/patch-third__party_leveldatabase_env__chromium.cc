--- third_party/leveldatabase/env_chromium.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/leveldatabase/env_chromium.cc
@@ -316,7 +316,8 @@ ChromiumWritableFile::ChromiumWritableFile(const std::
 
 Status ChromiumWritableFile::SyncParent() {
   TRACE_EVENT0("leveldb", "SyncParent");
-#if defined(OS_POSIX) || defined(OS_FUCHSIA)
+// pledge violation (directory passed as fd)
+#if (defined(OS_POSIX) || defined(OS_FUCHSIA)) && !defined(OS_OPENBSD)
   FilePath path = FilePath::FromUTF8Unsafe(parent_dir_);
   FileErrorOr<base::File> result = filesystem_->OpenFile(
       path, base::File::FLAG_OPEN | base::File::FLAG_READ);
