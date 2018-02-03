--- mtl/template.mk.orig	2018-02-03 20:34:58 UTC
+++ mtl/template.mk
@@ -18,8 +18,8 @@ DCOBJS     = $(addsuffix d,  $(COBJS))
 RCOBJS     = $(addsuffix r,  $(COBJS))
 
 CXX       ?= g++
-CFLAGS    ?= -Wall -Wno-parentheses -std=c++11
-LFLAGS    ?= -Wall -lpthread 
+CFLAGS    += -Wall -Wno-parentheses -std=c++11
+LFLAGS    += -Wall -lpthread 
 
 COPTIMIZE ?= -O3
 
