--- config/config.mk.orig	Thu Oct 31 23:24:59 2002
+++ config/config.mk	Thu Oct 31 23:27:02 2002
@@ -33,8 +33,8 @@
 #
 ###############################################################################
 
-#FREE_BSD:=	-DFreeBSD
-LINUX:=		-DLinux -D_BSD_SOURCE
+FREE_BSD:=	-DFreeBSD
+#LINUX:=		-DLinux -D_BSD_SOURCE
 #MAC_OS_X:=	-DMacOSX
 #SOLARIS:=	-DSolaris
 #WIN32:=		-DWIN32
@@ -99,7 +99,6 @@
 ifdef SEARCH_DAEMON
 
 ifdef FREE_BSD
-PTHREAD_LIB:=	-pthread
 else
 PTHREAD_LIB:=	-lpthread
 endif
@@ -130,7 +129,7 @@
 #		The command to remove files recursively and ignore errors;
 #		usually "rm -fr" for Unix or "erase" for Windows.
 
-PERL:=		/usr/local/bin/perl
+#PERL:=		/usr/local/bin/perl
 #		The full path to the Perl 5 executable; usually "/bin/perl" or
 #		"/usr/local/bin/perl" for Unix or "\Perl\bin\perl" for
 #		Windows.  You need this only if you intend on using
@@ -164,7 +163,7 @@
 ifdef DEBUG
 OPTIM:=		-g
 else
-OPTIM:=		-O2
+OPTIM:=		${CXXFLAGS}
 #		The optimization level.  Many compilers allow a digit after the
 #		O to specify the level of optimization; if so, set yours to the
 #		highest number your compiler allows without eliciting problems
@@ -208,7 +207,7 @@
 INSTALL:=	$(ROOT)/install-sh
 #		Install command; usually "$(ROOT)/install-sh".
 
-I_ROOT:=	/usr/local
+I_ROOT:=	${PREFIX}
 #		The top-level directory of where SWISH++ will be installed.
 
 I_BIN:=		$(I_ROOT)/bin
