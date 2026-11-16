-- Allow the cadical build to place its binary and static library in a
-- directory other than the hardcoded `../..` path. CMake passes
-- CADICAL_OUT=${CMAKE_BINARY_DIR}/cadical so the pre-fetched GH_TUPLE
-- source can be built in place while outputs land where the rest of the
-- Lean build expects them.
--- src/cadical.mk.orig	2026-11-16 02:28:42 UTC
+++ src/cadical.mk
@@ -1,19 +1,26 @@ AR ?= ar
 CXX ?= c++
 AR ?= ar
 
+# Output directory for the cadical binary and libcadical.a.
+# The default `../..` matches the original ExternalProject_Add layout where
+# the source lived at ${CMAKE_BINARY_DIR}/cadical/src/cadical. FreeBSD ports
+# extract the source under the port's WRKSRC, so CMake overrides this to
+# ${CMAKE_BINARY_DIR}/cadical.
+CADICAL_OUT ?= ../..
+
 OBJS = $(patsubst src/%.cpp,%.o,$(shell ls src/*.cpp | grep -v mobical))
 # `cadical.cpp` provides the command line application's `main`
 LIB_OBJS = $(filter-out cadical.o,$(OBJS))
 
 .PHONY: all
-all: ../../cadical$(CMAKE_EXECUTABLE_SUFFIX) ../../libcadical.a
+all: $(CADICAL_OUT)/cadical$(CMAKE_EXECUTABLE_SUFFIX) $(CADICAL_OUT)/libcadical.a
 
 %.o: src/%.cpp
 	$(CXX) -std=c++11 -O3 -DNDEBUG -DNBUILD $(CXXFLAGS) -c $< -o $@
 
-../../cadical$(CMAKE_EXECUTABLE_SUFFIX): $(OBJS)
+$(CADICAL_OUT)/cadical$(CMAKE_EXECUTABLE_SUFFIX): $(OBJS)
 	$(CXX) -o $@ $^ $(LDFLAGS)
 
-../../libcadical.a: $(LIB_OBJS)
+$(CADICAL_OUT)/libcadical.a: $(LIB_OBJS)
 	rm -f $@
 	$(AR) rcs $@ $^
