--- core/cmake/BareosDetermineHaveLowLevelScsiInterface.cmake	2025-12-18 20:01:29.947071000 -0800
+++ core/cmake/BareosDetermineHaveLowLevelScsiInterface.cmake	2025-12-18 20:01:40.919760000 -0800
@@ -53,7 +53,7 @@
   if(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
     if("${HAVE_CAMLIB_H}" AND "${HAVE_CAM_SCSI_SCSI_MESSAGE_H}")
       set(HAVE_LOWLEVEL_SCSI_INTERFACE 1)
-      target_link_libraries(bareos-low-level-scsi PRIVATE cam)
+      target_link_libraries(bareos-low-level-scsi INTERFACE cam)
     else()
       set(HAVE_LOWLEVEL_SCSI_INTERFACE 0)
       message(
