--- Misc.cpp.orig	2020-11-19 18:24:13 UTC
+++ Misc.cpp
@@ -511,7 +511,7 @@ wxArrayString output, errors;
 wxCHECK_MSG(!lib.empty(), "", "Empty parameter");
 
 wxArrayString output, errors;
-long ans = wxExecute("sh -c \"/sbin/ldconfig -p | grep " + lib + '\"', output,errors);
+long ans = wxExecute("sh -c \"/sbin/ldconfig -r | grep " + lib + '\"', output,errors);
 if (ans != 0 || output.IsEmpty()) return "";
 
 wxString fpath = output.Item(0).AfterLast(' ');
@@ -666,7 +666,12 @@ if (clientDC) delete clientDC;
 #endif
 //-----------------------------------------------------------------------------------------------------------------------
 
+#ifdef __linux__
 #include <pty.h>
+#else
+#include <termios.h>
+#include <libutil.h>
+#endif
 #include <errno.h>
 #include <sys/wait.h>
 
@@ -779,7 +784,7 @@ if (cmd.empty()) return ERROR_RETURN_CODE;
 {
 if (cmd.empty()) return ERROR_RETURN_CODE;
 
-if (wxGetOsDescription().Contains(wxT("kFreeBSD"))) // The kFreeBSD forkpty hangs
+if (wxGetOsDescription().Contains(wxT("FreeBSD"))) // FreeBSD's forkpty() hangs
   { if (GetCallerTextCtrl())
       InformCallerOnTerminate();
     return ERROR_RETURN_CODE;
