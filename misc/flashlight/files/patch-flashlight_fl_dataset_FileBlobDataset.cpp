- workaround for https://github.com/flashlight/flashlight/issues/1087

--- flashlight/fl/dataset/FileBlobDataset.cpp.orig	2023-03-15 07:10:45 UTC
+++ flashlight/fl/dataset/FileBlobDataset.cpp
@@ -72,7 +72,7 @@ int64_t FileBlobDataset::writeData(
   auto fs = getStream();
   fs->seekp(offset, std::ios_base::beg);
   fs->write(data, size);
-  return fs->tellp() - offset;
+  return int64_t(fs->tellp()) - offset;
 }
 
 int64_t FileBlobDataset::readData(int64_t offset, char* data, int64_t size)
@@ -80,7 +80,7 @@ int64_t FileBlobDataset::readData(int64_t offset, char
   auto fs = getStream();
   fs->seekg(offset, std::ios_base::beg);
   fs->read(data, size);
-  return fs->tellg() - offset;
+  return int64_t(fs->tellg()) - offset;
 }
 
 void FileBlobDataset::flushData() {
