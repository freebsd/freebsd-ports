--- libretroshare/src/rsserver/rsinit.cc.org	2012-01-15 04:34:27.000000000 +0100
+++ libretroshare/src/rsserver/rsinit.cc	2012-01-15 04:35:45.000000000 +0100
@@ -59,78 +59,14 @@
 
 #include "tcponudp/udpstunner.h"
 
-class accountId
-{
-	public:
-		std::string pgpId;
-		std::string pgpName;
-		std::string pgpEmail;
-
-		std::string sslId;
-                std::string location;
-};
-
-
-class RsInitConfig 
-{
-	public:
-                /* Directories (SetupBaseDir) */
-                static std::string basedir;
-                static std::string homePath;
-#ifdef WINDOWS_SYS
-                static bool portable;
-                static bool isWindowsXP;
-#endif
-
-		static std::list<accountId> accountIds;
-		static std::string preferedId;
-
-		/* for certificate creation */
-                //static std::string gpgPasswd;
-
-#ifndef WINDOWS_SYS
-		static int lockHandle;
-#else
-		static HANDLE lockHandle;
-#endif
-
-		/* These fields are needed for login */
-                static std::string loginId;
-                static std::string configDir;
-                static std::string load_cert;
-                static std::string load_key;
-
-		static std::string passwd;
-
-                static bool autoLogin;                  /* autoLogin allowed */
-                static bool startMinimised; 		/* Icon or Full Window */
-
-                /* Key Parameters that must be set before
-                 * RetroShare will start up:
-                 */
-
-                /* Listening Port */
-                static bool forceExtPort;
-                static bool forceLocalAddr;
-                static unsigned short port;
-                static char inet[256];
-
-                /* Logging */
-                static bool haveLogFile;
-                static bool outStderr;
-                static bool haveDebugLevel;
-                static int  debugLevel;
-                static std::string logfname;
-
-                static bool firsttime_run;
-                static bool load_trustedpeer;
-                static std::string load_trustedpeer_file;
-
-                static bool udpListenerOnly;
-
-                static std::string RetroShareLink;
-};
+#include "rsinit.h"
 
+#include <fnmatch.h>
+#include <unistd.h>
+#define O_LARGEFILE      0100000
+#define stat64 stat
+#define _stat stat
+#define _getcwd getcwd
 
 const int p3facestartupzone = 47238;
 
