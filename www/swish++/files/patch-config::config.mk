--- config/config.mk.orig	Sun Jan 13 11:38:36 2002
+++ config/config.mk	Sun Jan 13 11:41:51 2002
@@ -35,8 +35,8 @@
 #
 ###############################################################################
 
-#FREE_BSD:=	-DFreeBSD
-LINUX:=		-DLinux
+FREE_BSD:=	-DFreeBSD
+#LINUX:=		-DLinux
 #SOLARIS:=	-DSolaris
 #WIN32:=		-DWIN32
 
@@ -87,7 +87,6 @@
 ifdef SEARCH_DAEMON
 
 ifdef FREE_BSD
-PTHREAD_LIB:=	-pthread
 else
 PTHREAD_LIB:=	-lpthread
 endif
@@ -118,7 +117,6 @@
 #		The command to remove files recursively and ignore errors;
 #		usually "rm -fr" for Unix or "erase" for Windows.
 
-PERL:=		/usr/local/bin/perl
 #		The full path to the Perl 5 executable; usually "/bin/perl" or
 #		"/usr/local/bin/perl" for Unix or "\Perl\bin\perl" for
 #		Windows.  You need this only if you intend on using
@@ -145,15 +143,14 @@
 #
 ###############################################################################
 
-#CC:=		g++
-CC:=		/usr/local/bin/g++
+CC:=		g++
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
@@ -196,7 +193,7 @@
 INSTALL:=	$(ROOT)/install-sh
 #		Install command; usually "$(ROOT)/install-sh".
 
-I_ROOT:=	/usr/local
+I_ROOT:=	${PREFIX}
 #		The top-level directory of where SWISH++ will be installed.
 
 I_BIN:=		$(I_ROOT)/bin
