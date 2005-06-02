--- clientgui/BOINCGUIApp.cpp.orig	Wed May 25 15:48:01 2005
+++ clientgui/BOINCGUIApp.cpp	Wed Jun  1 14:55:36 2005
@@ -110,10 +110,6 @@
         BOINC_DIAG_DUMPCALLSTACKENABLED | 
         BOINC_DIAG_HEAPCHECKENABLED |
         BOINC_DIAG_MEMORYLEAKCHECKENABLED |
-#if defined(__WXMSW__) || defined(__WXMAC__)
-        BOINC_DIAG_REDIRECTSTDERR |
-        BOINC_DIAG_REDIRECTSTDOUT |
-#endif
         BOINC_DIAG_TRACETOSTDOUT;
 
     diagnostics_init(
