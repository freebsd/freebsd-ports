--- config/config.mk.orig	Tue Dec 24 15:59:08 2002
+++ config/config.mk	Tue Apr 15 13:40:16 2003
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
@@ -112,7 +112,7 @@
 ifdef SEARCH_DAEMON
 
 ifdef FREE_BSD
-PTHREAD_LINK:=	-pthread
+PTHREAD_LINK:=	${PTHREAD_LIBS}
 else
 PTHREAD_LINK:=	-lpthread
 endif
@@ -149,7 +149,7 @@
 #		The command to remove files recursively and ignore errors;
 #		usually "rm -fr" for Unix or "erase" for Windows.
 
-PERL:=		/usr/local/bin/perl
+#PERL:=		/usr/local/bin/perl
 #		The full path to the Perl 5 executable; usually "/bin/perl" or
 #		"/usr/local/bin/perl" for Unix or "\Perl\bin\perl" for
 #		Windows.  You need this only if you intend on using
@@ -176,14 +176,14 @@
 #
 ###############################################################################
 
-CC:=		g++
+CC:=		${CXX}
 #		The C++ compiler you are using; usually "CC" or "g++".
 
 #DEBUG:=		true
 ifdef DEBUG
 OPTIM:=		-g
 else
-OPTIM:=		-O2
+OPTIM:=		${CXXFLAGS}
 #		The optimization level.  Many compilers allow a digit after the
 #		O to specify the level of optimization; if so, set yours to the
 #		highest number your compiler allows without eliciting problems
@@ -227,7 +227,7 @@
 INSTALL:=	$(ROOT)/install-sh
 #		Install command; usually "$(ROOT)/install-sh".
 
-I_ROOT:=	/usr/local
+I_ROOT:=	${PREFIX}
 #		The top-level directory of where SWISH++ will be installed.
 
 I_BIN:=		$(I_ROOT)/bin
