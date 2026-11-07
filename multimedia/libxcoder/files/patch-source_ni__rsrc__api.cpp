--- source/ni_rsrc_api.cpp.orig	2026-10-17 00:01:03 UTC
+++ source/ni_rsrc_api.cpp
@@ -32,7 +32,7 @@
 #include <errno.h>
 #include <ctype.h>
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #include <unistd.h>
 #include <fcntl.h> /* For O_* constants */
 #include <dirent.h>
@@ -657,7 +657,7 @@ END:
     return p_device_context;
 }
 
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
 #if __APPLE__
 #define DEV_NAME_PREFIX "rdisk"
 #elif defined(XCODER_LINUX_VIRTIO_DRIVER_ENABLED)
@@ -1350,7 +1350,7 @@ void ni_rsrc_free_device_context(ni_device_context_t *
 #ifdef _WIN32
     UnmapViewOfFile(p_device_context->p_device_info);
     ReleaseMutex(p_device_context->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     close(p_device_context->lock);
     ni_rsrc_munmap_shm((void *)p_device_context->p_device_info, sizeof(ni_device_info_t));
     ni_log(NI_LOG_DEBUG, "in %s do munmap for %s\n", __func__, p_device_context->shm_name);
@@ -1404,7 +1404,7 @@ ni_retcode_t ni_rsrc_list_devices(ni_device_type_t dev
     retval = NI_RETCODE_FAILURE;
     LRETURN;
   }
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
   lockf(p_device_pool->lock, F_LOCK, 0);
 #endif
 
@@ -1433,7 +1433,7 @@ ni_retcode_t ni_rsrc_list_devices(ni_device_type_t dev
 
       memcpy(&p_device_info[i], p_device_context->p_device_info, sizeof(ni_device_info_t));
       ReleaseMutex(p_device_context->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
       lockf(p_device_context->lock, F_LOCK, 0);
       memcpy(&p_device_info[i], p_device_context->p_device_info, sizeof(ni_device_info_t));
       lockf(p_device_context->lock, F_ULOCK, 0);
@@ -1455,7 +1455,7 @@ END:
     {
 #ifdef _WIN32
       ReleaseMutex(p_device_pool->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
       lockf(p_device_pool->lock, F_ULOCK, 0);
 #endif
     }
@@ -1871,7 +1871,7 @@ int ni_rsrc_get_device_by_block_name(const char *blk_n
         ni_rsrc_free_device_pool(p_device_pool);
         return NI_RETCODE_FAILURE;
     }
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     lockf(p_device_pool->lock, F_LOCK, 0);
 #endif
 
@@ -1895,7 +1895,7 @@ int ni_rsrc_get_device_by_block_name(const char *blk_n
 
 #ifdef _WIN32
     ReleaseMutex(p_device_pool->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     lockf(p_device_pool->lock, F_ULOCK, 0);
 #endif
 
@@ -1936,7 +1936,7 @@ int ni_rsrc_update_device_load(ni_device_context_t *p_
              __func__, p_device_context->lock);
       return NI_RETCODE_FAILURE;
   }
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
   lockf(p_device_context->lock, F_LOCK, 0);
 #endif
 
@@ -1949,7 +1949,7 @@ int ni_rsrc_update_device_load(ni_device_context_t *p_
 
 #ifdef _WIN32
   ReleaseMutex(p_device_context->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
   lockf(p_device_context->lock, F_ULOCK, 0);
 #endif
 
@@ -2016,7 +2016,7 @@ void ni_rsrc_release_resource(ni_device_context_t *p_d
       ni_log(NI_LOG_ERROR, "ERROR: %s() failed to obtain mutex: %p\n",
              __func__, p_device_context->lock);
   }
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
   lockf(p_device_context->lock, F_LOCK, 0);
 #endif
 
@@ -2030,7 +2030,7 @@ void ni_rsrc_release_resource(ni_device_context_t *p_d
     p_device_context->p_device_info->xcode_load_pixel -= load;
     // Remove as the value is getting from the FW
     // p_device_context->p_device_info->model_load = (int)((double)(p_device_context->p_device_info->xcode_load_pixel) * 100 / total_cap);
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
     if (msync((void *)p_device_context->p_device_info, sizeof(ni_device_info_t), MS_SYNC | MS_INVALIDATE))
     {
         char errmsg[NI_ERRNO_LEN] = {0};
@@ -2043,7 +2043,7 @@ void ni_rsrc_release_resource(ni_device_context_t *p_d
 
 #ifdef _WIN32
   ReleaseMutex(p_device_context->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
   lockf(p_device_context->lock, F_ULOCK, 0);
 #endif
 
@@ -2259,7 +2259,7 @@ int ni_rsrc_remove_device(const char* dev)
 *******************************************************************************/
 int ni_rsrc_remove_device(const char* dev)
 {
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
     char lck_name[32];
 #endif
     int return_value = NI_RETCODE_SUCCESS;
@@ -2300,7 +2300,7 @@ int ni_rsrc_remove_device(const char* dev)
         return_value = NI_RETCODE_FAILURE;
         LRETURN;
     }
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     lockf(p_device_pool->lock, F_LOCK, 0);
 #endif
 
@@ -2346,7 +2346,7 @@ int ni_rsrc_remove_device(const char* dev)
 
 #ifdef _WIN32
             CloseHandle(p_device_context->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
             if (!ni_rsrc_remove_shm(p_device_context->shm_name, sizeof(ni_device_info_t)))
             {
                 ni_log(NI_LOG_INFO,
@@ -2371,7 +2371,7 @@ int ni_rsrc_remove_device(const char* dev)
 
             ni_rsrc_free_device_context(p_device_context);
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
             ni_rsrc_get_lock_name(device_type, guid, lck_name, 32);
             if (!unlink(lck_name))
             {
@@ -2430,7 +2430,7 @@ int ni_rsrc_remove_device(const char* dev)
         memcpy(p_device_queue->xcoders[ui_device_type], guids, sizeof(guids));
     }
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #ifndef _ANDROID
     if (!msync((void *)p_device_queue,
                sizeof(ni_device_queue_t),
@@ -2453,7 +2453,7 @@ int ni_rsrc_remove_device(const char* dev)
 
 #ifdef _WIN32
     ReleaseMutex(p_device_pool->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     lockf(p_device_pool->lock, F_ULOCK, 0);
 #endif
 
@@ -2540,7 +2540,7 @@ int ni_rsrc_remove_all_devices(void)
         }
     }
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
     if (!ni_rsrc_remove_shm(CODERS_SHM_NAME, sizeof(ni_device_queue_t)))
     {
         ni_log(NI_LOG_INFO, "%s deleted.\n", CODERS_SHM_NAME);
@@ -2621,7 +2621,7 @@ int ni_rsrc_add_device(const char* dev, int should_mat
                device_pool->lock);
         return NI_RETCODE_FAILURE;
     }
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     lockf(device_pool->lock, F_LOCK, 0);
 #endif
 
@@ -2674,7 +2674,7 @@ end:
 end:
 #ifdef _WIN32
     ReleaseMutex(device_pool->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     lockf(device_pool->lock, F_ULOCK, 0);
 #endif
     ni_rsrc_free_device_pool(device_pool);
@@ -2696,7 +2696,7 @@ void ni_rsrc_free_device_pool(ni_device_pool_t* p_devi
     {
 #ifdef _WIN32
         CloseHandle(p_device_pool->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
         close(p_device_pool->lock);
 #endif
     }
@@ -4311,7 +4311,7 @@ ni_device_context_t *ni_rsrc_allocate_auto(
     {
         ni_log(NI_LOG_ERROR, "ERROR: %s() failed to obtain mutex: %p\n", __func__, p_device_pool->lock);
     }
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     lockf(p_device_pool->lock, F_LOCK, 0);
 #endif
 
@@ -4366,7 +4366,7 @@ ni_device_context_t *ni_rsrc_allocate_auto(
             ni_log(NI_LOG_ERROR, "ERROR: %s() failed to obtain mutex: %p\n",
                    __func__, p_device_context->lock);
         }
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
         lockf(p_device_context->lock, F_LOCK, 0);
 #endif
         ni_rsrc_update_record(p_device_context, p_session_context);
@@ -4418,7 +4418,7 @@ ni_device_context_t *ni_rsrc_allocate_auto(
 
 #ifdef _WIN32
         ReleaseMutex(p_device_context->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
         lockf(p_device_context->lock, F_ULOCK, 0);
 #endif
         ni_rsrc_free_device_context(p_device_context);
@@ -4448,7 +4448,7 @@ END:
 END:
 #ifdef _WIN32
     ReleaseMutex(p_device_pool->lock);
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     lockf(p_device_pool->lock, F_ULOCK, 0);
 #endif
     ni_device_session_context_free(p_session_context);
