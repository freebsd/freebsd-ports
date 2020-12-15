--- core/cmake/BareosInstallConfigFiles.cmake	2020-12-11 10:27:01.000000000 -0500
+++ core/cmake/BareosInstallConfigFiles.cmake	2020-12-15 01:25:25.641687000 -0500
@@ -43,18 +43,9 @@
    get_filename_component(resname ${resdir} NAME)
    foreach(configfile ${configfiles})
       get_filename_component(fname ${configfile} NAME)
-      if (EXISTS ${DESTCONFDIR}/${resname}/${fname})
-         MESSAGE(STATUS "${DESTCONFDIR}/${resname}/${fname} exists")
-         MESSAGE(STATUS "rename ${configfile} to ${configfile}.new")
-         FILE (RENAME "${configfile}" "${configfile}.new")
-
-         MESSAGE(STATUS "copy ${configfile}.new to ${DESTCONFDIR}/${resname}")
-         FILE (INSTALL "${configfile}.new" DESTINATION "${DESTCONFDIR}/${resname}")
-         FILE (RENAME "${configfile}.new" "${configfile}")
-      else()
-         MESSAGE(STATUS "${resname}/${fname} as ${resname}/${fname} (new installation)")
-         FILE (COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
-      endif()
+      MESSAGE(STATUS "${resname}/${fname} as ${resname}/${fname}.sample (new installation)")
+      FILE (RENAME "${configfile}" "${configfile}.sample")
+      FILE (COPY "${configfile}.sample" DESTINATION "${DESTCONFDIR}/${resname}")
    endforeach()
 endforeach()
 
@@ -82,21 +73,16 @@
       get_filename_component(dir   ${configfile} DIRECTORY)
       get_filename_component(fname ${configfile} NAME)
 
-      if (EXISTS ${DESTCONFDIR}/${configfile})
-         MESSAGE(STATUS "${configfile} as ${configfile}.new (keep existing)")
-         FILE(RENAME "${BackendConfigSrcDir}/${configfile}" "${BackendConfigSrcDir}/${configfile}.new")
-         FILE(COPY   "${BackendConfigSrcDir}/${configfile}.new" DESTINATION "${DESTCONFDIR}/${dir}")
-         FILE(RENAME "${BackendConfigSrcDir}/${configfile}.new" "${BackendConfigSrcDir}/${configfile}")
-      else()
-         MESSAGE(STATUS "${configfile} as ${configfile}")
-         FILE(COPY "${BackendConfigSrcDir}/${configfile}" DESTINATION "${DESTCONFDIR}/${dir}")
-      endif()
+      MESSAGE(STATUS "${configfile} as ${configfile}")
+      FILE(RENAME "${BackendConfigSrcDir}/${configfile}" "${BackendConfigSrcDir}/${configfile}.sample")
+      FILE(COPY "${BackendConfigSrcDir}/${configfile}.sample" DESTINATION "${DESTCONFDIR}/${dir}")
    endforeach()
 
    file(GLOB_RECURSE configfiles RELATIVE "${BackendConfigSrcDir}" "${BackendConfigSrcDir}/*.example")
    foreach(configfile ${configfiles})
       get_filename_component(dir   ${configfile} DIRECTORY)
-      #get_filename_component(fname ${configfile} NAME)
+      get_filename_component(fname ${configfile} NAME)
+      get_filename_component(fsname ${configfile} NAME_WE)
 
       if (EXISTS ${DESTCONFDIR}/${configfile})
          MESSAGE(STATUS "overwriting ${configfile}")
@@ -104,7 +90,8 @@
          MESSAGE(STATUS "${configfile} as ${configfile}")
       endif()
 
-      FILE(COPY "${BackendConfigSrcDir}/${configfile}" DESTINATION "${DESTCONFDIR}/${dir}")
+      FILE(RENAME "${BackendConfigSrcDir}/${configfile}" "${BackendConfigSrcDir}/${fsname}.conf.sample")
+      FILE(COPY "${BackendConfigSrcDir}/${fsname}.conf.sample" DESTINATION "${DESTCONFDIR}/${dir}")
    endforeach()
 
 ENDFOREACH()
@@ -122,15 +109,13 @@
          STRING(REGEX MATCH "\\.in\$" IS_INFILE ${configfile})
          if (NOT "${IS_INFILE}" STREQUAL ".in")
             get_filename_component(fname ${configfile} NAME)
-            if (EXISTS ${DESTCONFDIR}/${resname}/${fname})
-               MESSAGE(STATUS "${resname}/${fname} as ${resname}/${fname}.new (keep existing)")
-               FILE (RENAME "${configfile}" "${configfile}.new")
-               FILE (COPY "${configfile}.new" DESTINATION "${DESTCONFDIR}/${resname}")
-               FILE (RENAME "${configfile}.new" "${configfile}")
-            else()
-               MESSAGE(STATUS "${resname}/${fname} as ${resname}/${fname}")
-               FILE (COPY "${configfile}" DESTINATION "${DESTCONFDIR}/${resname}")
-            endif()
+            get_filename_component(fsname ${configfile} NAME_WE)
+            MESSAGE(STATUS "${resname}/${fname} as ${resname}/${fname}")
+            FILE(RENAME "${configfile}" "${resdir}/${fsname}.conf.sample")
+            FILE(
+             COPY "${resdir}/${fsname}.conf.sample"
+             DESTINATION "${DESTCONFDIR}/${resname}"
+            )
          else()
             MESSAGE(STATUS "skipping .in file ${configfile}:${IS_INFILE}")
          endif()
