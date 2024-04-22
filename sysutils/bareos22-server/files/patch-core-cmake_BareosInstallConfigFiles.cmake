--- core/cmake/BareosInstallConfigFiles.cmake	2023-12-13 07:48:37.000000000 -0500
+++ core/cmake/BareosInstallConfigFiles.cmake	2024-01-05 01:02:51.562611000 -0500
@@ -27,27 +27,13 @@
   endif()
 
   get_filename_component(fname ${configfile} NAME)
-  if(EXISTS ${DESTCONFDIR}${additionalconfigdir}/${fname})
-    message(
-      STATUS "${DESTCONFDIR}${additionalconfigdir}/${fname} already exists"
-    )
-    message(
-      STATUS
-        "Installing config: ${DESTCONFDIR}${additionalconfigdir}/${fname}.new"
-    )
-    file(RENAME "${configfile}" "${configfile}.new")
-    file(COPY "${configfile}.new"
-         DESTINATION "${DESTCONFDIR}${additionalconfigdir}"
-    )
-    file(RENAME "${configfile}.new" "${configfile}")
-  else()
-    message(
-      STATUS "Installing config: ${DESTCONFDIR}${additionalconfigdir}/${fname}"
-    )
-    file(COPY "${configfile}"
-         DESTINATION "${DESTCONFDIR}${additionalconfigdir}"
-    )
-  endif()
+
+  message(STATUS "${DESTCONFDIR}${additionalconfigdir}/${fname} as ${DESTCONFDIR}${additionalconfigdir}/${fname}.sample (new installation)")
+  file(RENAME "${configfile}" "${configfile}.sample")
+  file(                                                             
+       COPY "${configfile}.sample"                                      
+       DESTINATION "${DESTCONFDIR}${additionalconfigdir}"
+  )
 endfunction()
 
 macro(BareosInstallConfigFiles CONFDIR CONFIGBASEDIRECTORY PLUGINS BACKENDS
@@ -125,23 +111,12 @@
       get_filename_component(dir ${configfile} DIRECTORY)
       get_filename_component(fname ${configfile} NAME)
 
-      if(EXISTS ${DESTCONFDIR}/${configfile})
-        message(STATUS "${configfile} as ${configfile}.new (keep existing)")
-        file(RENAME "${BackendConfigSrcDir}/${configfile}"
-             "${BackendConfigSrcDir}/${configfile}.new"
-        )
-        file(COPY "${BackendConfigSrcDir}/${configfile}.new"
-             DESTINATION "${DESTCONFDIR}/${dir}"
-        )
-        file(RENAME "${BackendConfigSrcDir}/${configfile}.new"
-             "${BackendConfigSrcDir}/${configfile}"
-        )
-      else()
-        message(STATUS "${configfile} as ${configfile}")
-        file(COPY "${BackendConfigSrcDir}/${configfile}"
-             DESTINATION "${DESTCONFDIR}/${dir}"
-        )
-      endif()
+      message(STATUS "${configfile} as ${configfile}.sample")
+      file(RENAME "${BackendConfigSrcDir}/${configfile}" "${BackendConfigSrcDir}/${configfile}.sample")
+      file(
+       COPY "${BackendConfigSrcDir}/${configfile}.sample"
+       DESTINATION "${DESTCONFDIR}/${dir}"
+      )
     endforeach()
 
     file(
@@ -151,7 +126,8 @@
     )
     foreach(configfile ${configfiles})
       get_filename_component(dir ${configfile} DIRECTORY)
-      # get_filename_component(fname ${configfile} NAME)
+      get_filename_component(fname ${configfile} NAME)
+      get_filename_component(fsname ${configfile} NAME_WE)
 
       if(EXISTS ${DESTCONFDIR}/${configfile})
         message(STATUS "overwriting ${configfile}")
@@ -159,8 +135,10 @@
         message(STATUS "${configfile} as ${configfile}")
       endif()
 
-      file(COPY "${BackendConfigSrcDir}/${configfile}"
-           DESTINATION "${DESTCONFDIR}/${dir}"
+      file(RENAME "${BackendConfigSrcDir}/${configfile}" "${BackendConfigSrcDir}/${fsname}.conf.sample")
+      file(
+       COPY "${BackendConfigSrcDir}/${fsname}.conf.sample"
+       DESTINATION "${DESTCONFDIR}/${dir}"
       )
     endforeach()
 
@@ -188,20 +166,13 @@
         string(REGEX MATCH "\\.in\$" IS_INFILE ${configfile})
         if(NOT "${IS_INFILE}" STREQUAL ".in")
           get_filename_component(fname ${configfile} NAME)
-          if(EXISTS ${DESTCONFDIR}/${resname}/${fname})
-            message(
-              STATUS
-                "${resname}/${fname} as ${resname}/${fname}.new (keep existing)"
-            )
-            file(RENAME "${configfile}" "${configfile}.new")
-            file(COPY "${configfile}.new"
-                 DESTINATION "${DESTCONFDIR}/${resname}"
-            )
-            file(RENAME "${configfile}.new" "${configfile}")
-          else()
-            message(STATUS "${resname}/${fname} as ${resname}/${fname}")
-            file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
-          endif()
+          get_filename_component(fsname ${configfile} NAME_WE)
+          message(STATUS "${resname}/${fname} as ${resname}/${fname}")
+          file(RENAME "${configfile}" "${resdir}/${fsname}.conf.sample")
+          file(
+            COPY "${resdir}/${fsname}.conf.sample"
+            DESTINATION "${DESTCONFDIR}/${resname}"
+          )
         else()
           message(STATUS "skipping .in file ${configfile}:${IS_INFILE}")
         endif()
