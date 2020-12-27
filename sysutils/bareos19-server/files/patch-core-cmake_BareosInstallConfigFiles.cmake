--- core/cmake/BareosInstallConfigFiles.cmake	2020-01-31 11:21:18.000000000 -0500
+++ core/cmake/BareosInstallConfigFiles.cmake	2020-02-03 02:15:35.557127000 -0500
@@ -60,24 +60,12 @@
     get_filename_component(resname ${resdir} NAME)
     foreach(configfile ${configfiles})
       get_filename_component(fname ${configfile} NAME)
-      if(EXISTS ${DESTCONFDIR}/${resname}/${fname})
-        message(STATUS "${DESTCONFDIR}/${resname}/${fname} exists")
-        message(STATUS "rename ${configfile} to ${configfile}.new")
-        file(RENAME "${configfile}" "${configfile}.new")
-
-        message(STATUS "copy ${configfile}.new to ${DESTCONFDIR}/${resname}")
-        file(
-          INSTALL "${configfile}.new"
-          DESTINATION "${DESTCONFDIR}/${resname}"
-        )
-        file(RENAME "${configfile}.new" "${configfile}")
-      else()
-        message(
-          STATUS
-            "${resname}/${fname} as ${resname}/${fname} (new installation)"
-        )
-        file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
-      endif()
+      message(STATUS "${resname}/${fname} as ${resname}/${fname}.sample (new installation)")
+      file(RENAME "${configfile}" "${configfile}.sample")
+      file(
+	COPY "${configfile}.sample"
+	DESTINATION "${DESTCONFDIR}/${resname}"
+      )
     endforeach()
   endforeach()
 
@@ -114,23 +102,12 @@
       get_filename_component(dir ${configfile} DIRECTORY)
       get_filename_component(fname ${configfile} NAME)
 
-      if(EXISTS ${DESTCONFDIR}/${configfile})
-        message(STATUS "${configfile} as ${configfile}.new (keep existing)")
-        file(RENAME "${BackendConfigSrcDir}/${configfile}"
-             "${BackendConfigSrcDir}/${configfile}.new")
-        file(
-          COPY "${BackendConfigSrcDir}/${configfile}.new"
-          DESTINATION "${DESTCONFDIR}/${dir}"
-        )
-        file(RENAME "${BackendConfigSrcDir}/${configfile}.new"
-             "${BackendConfigSrcDir}/${configfile}")
-      else()
-        message(STATUS "${configfile} as ${configfile}")
-        file(
-          COPY "${BackendConfigSrcDir}/${configfile}"
-          DESTINATION "${DESTCONFDIR}/${dir}"
-        )
-      endif()
+      message(STATUS "${configfile} as ${configfile}")
+      file(RENAME "${BackendConfigSrcDir}/${configfile}" "${BackendConfigSrcDir}/${configfile}.sample")
+      file(
+	COPY "${BackendConfigSrcDir}/${configfile}.sample"
+	DESTINATION "${DESTCONFDIR}/${dir}"
+      )
     endforeach()
 
     file(
@@ -140,7 +117,8 @@
     )
     foreach(configfile ${configfiles})
       get_filename_component(dir ${configfile} DIRECTORY)
-      # get_filename_component(fname ${configfile} NAME)
+      get_filename_component(fname ${configfile} NAME)
+      get_filename_component(fsname ${configfile} NAME_WE)
 
       if(EXISTS ${DESTCONFDIR}/${configfile})
         message(STATUS "overwriting ${configfile}")
@@ -148,9 +126,10 @@
         message(STATUS "${configfile} as ${configfile}")
       endif()
 
+      file(RENAME "${BackendConfigSrcDir}/${configfile}" "${BackendConfigSrcDir}/${fsname}.conf.sample")
       file(
-        COPY "${BackendConfigSrcDir}/${configfile}"
-        DESTINATION "${DESTCONFDIR}/${dir}"
+	COPY "${BackendConfigSrcDir}/${fsname}.conf.sample"
+	DESTINATION "${DESTCONFDIR}/${dir}"
       )
     endforeach()
 
@@ -174,22 +153,14 @@
         )
         if(NOT "${IS_INFILE}" STREQUAL ".in")
           get_filename_component(fname ${configfile} NAME)
-          if(EXISTS ${DESTCONFDIR}/${resname}/${fname})
-            message(
-              STATUS
-                "${resname}/${fname} as ${resname}/${fname}.new (keep existing)"
-            )
-            file(RENAME "${configfile}" "${configfile}.new")
-            file(
-              COPY "${configfile}.new"
-              DESTINATION "${DESTCONFDIR}/${resname}"
-            )
-            file(RENAME "${configfile}.new" "${configfile}")
-          else()
-            message(STATUS "${resname}/${fname} as ${resname}/${fname}")
-            file(COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
-          endif()
-        else()
+	  get_filename_component(fsname ${configfile} NAME_WE)
+          message(STATUS "${resname}/${fname} as ${resname}/${fname}")
+          file(RENAME "${configfile}" "${resdir}/${fsname}.conf.sample")
+          file(
+	    COPY "${resdir}/${fsname}.conf.sample"
+	    DESTINATION "${DESTCONFDIR}/${resname}"
+          )
+       else()
           message(STATUS "skipping .in file ${configfile}:${IS_INFILE}")
         endif()
       endforeach()
