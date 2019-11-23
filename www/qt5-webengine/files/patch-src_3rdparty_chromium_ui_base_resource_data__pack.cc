--- src/3rdparty/chromium/ui/base/resource/data_pack.cc.orig	2019-10-27 17:39:58 UTC
+++ src/3rdparty/chromium/ui/base/resource/data_pack.cc
@@ -154,16 +154,42 @@ class ScopedFileWriter {
   DISALLOW_COPY_AND_ASSIGN(ScopedFileWriter);
 };
 
+static inline uint16_t byteswap(uint16_t v) { return __builtin_bswap16(v); }
+static inline uint32_t byteswap(uint32_t v) { return __builtin_bswap32(v); }
+
+template<class T> class byteswapped_t {
+private:
+  T value;
+public:
+  inline byteswapped_t(T v) : value(byteswap(v)) { }
+  inline T operator=(T v) { value = byteswap(v); return v; }
+  inline T operator+=(T v) { v += byteswap(value); value = byteswap(v); return v; }
+  inline operator T() const { return byteswap(value); }
+};
+
+#if !defined(ARCH_CPU_LITTLE_ENDIAN)
+
+typedef byteswapped_t<uint16_t> uint16le_t;
+typedef byteswapped_t<uint32_t> uint32le_t;
+
+#else
+
+typedef uint16_t uint16le_t;
+typedef uint32_t uint32le_t;
+
+#endif
+
 }  // namespace
 
 namespace ui {
 
 #pragma pack(push, 2)
 struct DataPack::Entry {
-  uint16_t resource_id;
-  uint32_t file_offset;
+  uint16le_t resource_id;
+  uint32le_t file_offset;
 
   static int CompareById(const void* void_key, const void* void_entry) {
+    // Key is host endian
     uint16_t key = *reinterpret_cast<const uint16_t*>(void_key);
     const Entry* entry = reinterpret_cast<const Entry*>(void_entry);
     return key - entry->resource_id;
@@ -171,10 +197,11 @@ struct DataPack::Entry {
 };
 
 struct DataPack::Alias {
-  uint16_t resource_id;
-  uint16_t entry_index;
+  uint16le_t resource_id;
+  uint16le_t entry_index;
 
   static int CompareById(const void* void_key, const void* void_entry) {
+    // Key is host endian
     uint16_t key = *reinterpret_cast<const uint16_t*>(void_key);
     const Alias* entry = reinterpret_cast<const Alias*>(void_entry);
     return key - entry->resource_id;
@@ -284,7 +311,7 @@ bool DataPack::LoadImpl(std::unique_ptr<DataPack::Data
   // Parse the version and check for truncated header.
   uint32_t version = 0;
   if (data_length > sizeof(version))
-    version = reinterpret_cast<const uint32_t*>(data)[0];
+    version = reinterpret_cast<const uint32le_t*>(data)[0];
   size_t header_length =
       version == kFileFormatV4 ? kHeaderLengthV4 : kHeaderLengthV5;
   if (version == 0 || data_length < header_length) {
@@ -295,14 +322,14 @@ bool DataPack::LoadImpl(std::unique_ptr<DataPack::Data
 
   // Parse the header of the file.
   if (version == kFileFormatV4) {
-    resource_count_ = reinterpret_cast<const uint32_t*>(data)[1];
+    resource_count_ = reinterpret_cast<const uint32le_t*>(data)[1];
     alias_count_ = 0;
     text_encoding_type_ = static_cast<TextEncodingType>(data[8]);
   } else if (version == kFileFormatV5) {
     // Version 5 added the alias table and changed the header format.
     text_encoding_type_ = static_cast<TextEncodingType>(data[4]);
-    resource_count_ = reinterpret_cast<const uint16_t*>(data)[4];
-    alias_count_ = reinterpret_cast<const uint16_t*>(data)[5];
+    resource_count_ = reinterpret_cast<const uint16le_t*>(data)[4];
+    alias_count_ = reinterpret_cast<const uint16le_t*>(data)[5];
   } else {
     LOG(ERROR) << "Bad data pack version: got " << version << ", expected "
                << kFileFormatV4 << " or " << kFileFormatV5;
@@ -382,12 +382,6 @@ bool DataPack::HasResource(uint16_t resource_id) const {
 
 bool DataPack::GetStringPiece(uint16_t resource_id,
                               base::StringPiece* data) const {
-  // It won't be hard to make this endian-agnostic, but it's not worth
-  // bothering to do right now.
-#if !defined(ARCH_CPU_LITTLE_ENDIAN)
-#error "datapack assumes little endian"
-#endif
-
   const Entry* target = LookupEntryById(resource_id);
   if (!target)
     return false;
@@ -447,9 +480,6 @@ void DataPack::CheckForDuplicateResources(
 bool DataPack::WritePack(const base::FilePath& path,
                          const std::map<uint16_t, base::StringPiece>& resources,
                          TextEncodingType text_encoding_type) {
-#if !defined(ARCH_CPU_LITTLE_ENDIAN)
-#error "datapack assumes little endian"
-#endif
   if (text_encoding_type != UTF8 && text_encoding_type != UTF16 &&
       text_encoding_type != BINARY) {
     LOG(ERROR) << "Invalid text encoding type, got " << text_encoding_type
@@ -467,7 +497,7 @@ bool DataPack::WritePack(const base::FilePath& path,
   if (!file.valid())
     return false;
 
-  uint32_t encoding = static_cast<uint32_t>(text_encoding_type);
+  uint32le_t encoding = static_cast<uint32le_t>(text_encoding_type);
 
   // Build a list of final resource aliases, and an alias map at the same time.
   std::vector<uint16_t> resource_ids;
@@ -494,13 +524,14 @@ bool DataPack::WritePack(const base::FilePath& path,
 
   // These values are guaranteed to fit in a uint16_t due to the earlier
   // check of |resources_count|.
-  const uint16_t alias_count = static_cast<uint16_t>(aliases.size());
-  const uint16_t entry_count = static_cast<uint16_t>(resource_ids.size());
+  const uint16le_t alias_count = static_cast<uint16le_t>(aliases.size());
+  const uint16le_t entry_count = static_cast<uint16le_t>(resource_ids.size());
   DCHECK_EQ(static_cast<size_t>(entry_count) + static_cast<size_t>(alias_count),
             resources_count);
 
-  file.Write(&kFileFormatV5, sizeof(kFileFormatV5));
-  file.Write(&encoding, sizeof(uint32_t));
+  uint32le_t version = kFileFormatV5;
+  file.Write(&version, sizeof(version));
+  file.Write(&encoding, sizeof(uint32le_t));
   file.Write(&entry_count, sizeof(entry_count));
   file.Write(&alias_count, sizeof(alias_count));
 
@@ -508,8 +539,8 @@ bool DataPack::WritePack(const base::FilePath& path,
   // last item so we can compute the size of the list item.
   const uint32_t index_length = (entry_count + 1) * sizeof(Entry);
   const uint32_t alias_table_length = alias_count * sizeof(Alias);
-  uint32_t data_offset = kHeaderLengthV5 + index_length + alias_table_length;
-  for (const uint16_t resource_id : resource_ids) {
+  uint32le_t data_offset = kHeaderLengthV5 + index_length + alias_table_length;
+  for (const uint16le_t resource_id : resource_ids) {
     file.Write(&resource_id, sizeof(resource_id));
     file.Write(&data_offset, sizeof(data_offset));
     data_offset += resources.find(resource_id)->second.length();
@@ -517,13 +548,13 @@ bool DataPack::WritePack(const base::FilePath& path,
 
   // We place an extra entry after the last item that allows us to read the
   // size of the last item.
-  const uint16_t resource_id = 0;
+  const uint16le_t resource_id = 0;
   file.Write(&resource_id, sizeof(resource_id));
   file.Write(&data_offset, sizeof(data_offset));
 
   // Write the aliases table, if any. Note: |aliases| is an std::map,
   // ensuring values are written in increasing order.
-  for (const std::pair<uint16_t, uint16_t>& alias : aliases) {
+  for (const std::pair<uint16le_t, uint16le_t> alias : aliases) {
     file.Write(&alias, sizeof(alias));
   }
 
