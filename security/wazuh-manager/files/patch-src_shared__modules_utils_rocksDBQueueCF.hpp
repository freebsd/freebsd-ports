--- src/shared_modules/utils/rocksDBQueueCF.hpp	2025-05-23 17:21:34.827040000 -0700
+++ src/shared_modules/utils/rocksDBQueueCF.hpp	2025-05-23 17:22:52.671141000 -0700
@@ -192,7 +192,7 @@
                     m_db->Delete(rocksdb::WriteOptions(), std::string(id) + "_" + std::to_string(index));
                 !status.ok())
             {
-                throw std::runtime_error("Failed to dequeue element: " + index);
+                throw std::runtime_error("Failed to dequeue element: " + std::to_string(index));
             }
             else
             {
@@ -291,7 +291,7 @@
                 {
                     if (status != rocksdb::Status::NotFound())
                     {
-                        throw std::runtime_error("Failed to get elements, error: " + status.code());
+                        throw std::runtime_error("Failed to get elements, error: " + std::to_string(status.code()));
                     }
                 }
                 ++index;
