--- mk/pthread.mk.orig	Fri Oct 31 22:36:21 2003
+++ mk/pthread.mk	Sun Feb 15 18:52:26 2004
@@ -35,7 +35,7 @@
 
 PTHREAD_TYPE   ?= native
 
-CFLAGS += -D_REENTRANT -D_THREAD_SAFE
+CFLAGS += ${PTHREAD_CFLAGS}
 
 ifeq (${PTHREAD_TYPE}, native) # native POSIX thread
 
@@ -48,11 +48,7 @@
 endif # CYGWIN
 
 ifeq (${HOST_OS}, FreeBSD)
-ifeq ($(shell ${TEST} ${OSVER} -lt 500016 && ${ECHO} yes), yes)
-LDFLAGS+= -pthread
-else # 500016
-LIBS   += -lc_r
-endif # 500016
+LIBS   += ${PTHREAD_LIBS}
 endif # FreeBSD
 
 ifeq (${HOST_OS}, Linux)
