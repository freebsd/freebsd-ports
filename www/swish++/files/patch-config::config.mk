--- config/config.mk.orig	Mon Nov 22 23:44:48 2004
+++ config/config.mk	Mon Nov 22 23:48:27 2004
@@ -34,8 +34,8 @@
 #
 ###############################################################################
 
-#FREE_BSD:=1
-LINUX:=1
+FREE_BSD:=1
+#LINUX:=1
 #MAC_OS_X:=1
 #SOLARIS:=1
 #WIN32:=1
@@ -118,7 +118,7 @@
 ifdef SEARCH_DAEMON
 
 ifdef FREE_BSD
-PTHREAD_LINK:=	-pthread
+PTHREAD_LINK:=	${PTHREAD_LIBS}
 else
 PTHREAD_LINK:=	-lpthread
 endif
@@ -159,7 +159,7 @@
 #		The command to remove files recursively and ignore errors;
 #		usually "rm -fr" for Unix or "erase" for Windows.
 
-PERL:=		/usr/local/bin/perl
+#PERL:=		/usr/local/bin/perl
 #		The full path to the Perl 5 executable; usually "/bin/perl" or
 #		"/usr/local/bin/perl" for Unix or "\Perl\bin\perl" for
 #		Windows.
@@ -185,14 +185,14 @@
 #
 ###############################################################################
 
-CC:=		g++
+CC:=       ${CXX}
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
@@ -254,7 +254,7 @@
 INSTALL:=	$(ROOT)/install-sh
 #		Install command; usually "$(ROOT)/install-sh".
 
-I_ROOT:=	/usr/local
+I_ROOT:=	${PREFIX}
 #		The top-level directory of where SWISH++ will be installed.
 
 I_BIN:=		$(I_ROOT)/bin
