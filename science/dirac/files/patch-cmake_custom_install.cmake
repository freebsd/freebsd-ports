-- fid symlink locations
-- upstreamed: https://gitlab.com/dirac/dirac/-/work_items/193

--- cmake/custom/install.cmake.orig	2026-04-10 17:09:54 UTC
+++ cmake/custom/install.cmake
@@ -45,9 +45,9 @@ install(
     WORLD_READ             WORLD_EXECUTE
     )
 # 3) remove real file
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/pam-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pam-dirac)")
 # 4) create symlink
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/pam ${CMAKE_INSTALL_PREFIX}/bin/pam-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/pam \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pam-dirac)")
 
 # workaround to install the utilities executable symlink:
 # 1) copy *.x to *-dirac
@@ -81,27 +81,27 @@ install(
     WORLD_READ             WORLD_EXECUTE
     )
 # 3) remove real files
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/diag-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/dirac_mointegral_export-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/mx2fit-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/pcmo_addlabels-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/polfit-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/twofit-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/vibcal-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/dirac_data-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/process_schema-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/bin/merge_amf-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/diag-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/dirac_mointegral_export-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/mx2fit-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcmo_addlabels-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/polfit-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/twofit-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vibcal-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/dirac_data-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/process_schema-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/merge_amf-dirac)")
 # 4) create symlink
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/diag.x ${CMAKE_INSTALL_PREFIX}/bin/diag-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/dirac_mointegral_export.x ${CMAKE_INSTALL_PREFIX}/bin/dirac_mointegral_export-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/mx2fit.x ${CMAKE_INSTALL_PREFIX}/bin/mx2fit-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/pcmo_addlabels.x ${CMAKE_INSTALL_PREFIX}/bin/pcmo_addlabels-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/polfit.x ${CMAKE_INSTALL_PREFIX}/bin/polfit-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/twofit.x ${CMAKE_INSTALL_PREFIX}/bin/twofit-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/vibcal.x ${CMAKE_INSTALL_PREFIX}/bin/vibcal-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/dirac_data.py ${CMAKE_INSTALL_PREFIX}/bin/dirac_data-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/process_schema.py ${CMAKE_INSTALL_PREFIX}/bin/process_schema-dirac)")
-install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/merge_amf.py ${CMAKE_INSTALL_PREFIX}/bin/merge_amf-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/diag.x \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/diag-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/dirac_mointegral_export.x \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/dirac_mointegral_export-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/mx2fit.x \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/mx2fit-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/pcmo_addlabels.x \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/pcmo_addlabels-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/polfit.x \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/polfit-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/twofit.x \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/twofit-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/vibcal.x \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vibcal-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/dirac_data.py \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/dirac_data-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/process_schema.py \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/process_schema-dirac)")
+install(CODE "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_INSTALL_PREFIX}/share/dirac/merge_amf.py \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/merge_amf-dirac)")
 
 # write git hash to build dir
 file(WRITE ${PROJECT_BINARY_DIR}/GIT_HASH "${_git_last_commit_hash}")
