--- config/config.mk.orig	Sun Apr  7 00:04:51 2002
+++ config/config.mk	Sun Apr  7 00:07:14 2002
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
@@ -152,7 +151,7 @@
 ifdef DEBUG
 OPTIM:=		-g
 else
-OPTIM:=		-O2
+OPTIM:=		${CXXFLAGS}
 #		The optimization level.  Many compilers allow a digit after the
 #		O to specify the level of optimization; if so, set yours to the
 #		highest number your compiler allows without eliciting problems
@@ -195,7 +194,7 @@
 INSTALL:=	$(ROOT)/install-sh
 #		Install command; usually "$(ROOT)/install-sh".
 
-I_ROOT:=	/usr/local
+I_ROOT:=	${PREFIX}
 #		The top-level directory of where SWISH++ will be installed.
 
 I_BIN:=		$(I_ROOT)/bin
