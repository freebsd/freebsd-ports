--- ./global_header.mk.orig	2011-06-27 09:59:22.000000000 +0400
+++ ./global_header.mk	2011-10-19 18:00:32.000000000 +0400
@@ -4,7 +4,7 @@
 #endef
 
 define thrift_template
-XTARGET := $(shell perl -e '@val = split("\/","$(2)"); $$last = pop(@val);split("\\.",$$last);print "$(1)/"."gen-cpp/"."@_[0]"."_types.cpp\n"' )
+XTARGET := $(shell perl -e '@val = split("\/","$(2)");$$last = pop(@val);@fields = split("\\.",$$last);print "$(1)/gen-cpp/@fields[0]_types.cpp\n"')
 
 ifneq ($$(XBUILT_SOURCES),) 
     XBUILT_SOURCES := $$(XBUILT_SOURCES) $$(XTARGET)
