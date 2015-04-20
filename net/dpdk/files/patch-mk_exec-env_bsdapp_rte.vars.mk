--- mk/exec-env/bsdapp/rte.vars.mk.orig	2015-04-20 12:36:29 UTC
+++ mk/exec-env/bsdapp/rte.vars.mk
@@ -40,13 +40,13 @@
 # examples for RTE_EXEC_ENV: linuxapp, bsdapp
 #
 ifeq ($(RTE_BUILD_SHARED_LIB),y)
-EXECENV_CFLAGS  = -pthread -fPIC
+EXECENV_CFLAGS  = -pthread -fPIC %%EXECINFO_CPPFLAGS%%
 else
-EXECENV_CFLAGS  = -pthread
+EXECENV_CFLAGS  = -pthread %%EXECINFO_CPPFLAGS%%
 endif
 
 EXECENV_LDFLAGS =
-EXECENV_LDLIBS  = -lexecinfo
+EXECENV_LDLIBS  = -lexecinfo %%EXECINFO_LDFLAGS%%
 EXECENV_ASFLAGS =
 
 ifeq ($(RTE_BUILD_SHARED_LIB),y)
