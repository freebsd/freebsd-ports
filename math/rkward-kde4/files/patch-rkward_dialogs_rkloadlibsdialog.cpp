--- rkward/dialogs/rkloadlibsdialog.cpp.orig	Mon Sep 11 00:59:43 2006
+++ rkward/dialogs/rkloadlibsdialog.cpp	Sun Sep 17 22:27:38 2006
@@ -38,6 +38,14 @@
 
 #include "../debug.h"
 
+#ifdef __FreeBSD__
+# include <sys/types.h>
+# include <unistd.h>
+# include <pwd.h>
+
+  struct passwd *passe;
+#endif
+
 #define GET_CURRENT_LIBLOCS_COMMAND 1
 
 RKLoadLibsDialog::RKLoadLibsDialog (QWidget *parent, RCommandChain *chain, bool modal) : KDialogBase (KDialogBase::Tabbed, Qt::WStyle_DialogBorder, parent, 0, modal, i18n ("Configure Packages"), KDialogBase::Ok | KDialogBase::Apply | KDialogBase::Cancel | KDialogBase::User1) {
@@ -166,7 +174,12 @@
 		QTextStream stream (&file);
 		stream << "options (repos=" + repos_string + ")\n" + command_string;
 		if (as_root) {
-			stream << QString ("system (\"chown ") + cuserid (0) + " " + QDir (RKSettingsModuleGeneral::filesPath ()).filePath ("package_archive") + "/*\")\n";
+			#ifdef __FreeBSD__
+			  passe = getpwuid((uid_t) 0);
+			  stream << QString ("system (\"chown ") + passe->pw_name + " " + QDir (RKSettingsModuleGeneral::filesPath ()).filePath ("package_archive") + "/*\")\n";
+			#else
+			  stream << QString ("system (\"chown ") + cuserid (0) + " " + QDir (RKSettingsModuleGeneral::filesPath ()).filePath ("package_archive") + "/*\")\n";
+			#endif
 		}
 		stream << "q ()\n";
 		file.close();
