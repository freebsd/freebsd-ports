# 
# Makefile for SDPA example(please use gmake)
# Sample Makefile written by <maho@FreeBSD.org>
#
# $FreeBSD$

PREFIX	      = %%PREFIX%%
LOCALBASE     = %%LOCALBASE%%
LAPACK_LIB    =	%%LAPACK%% %%CBLAS%%
SDPA_LIB      = -lsdpa
SDPA_EXAMPLES = example1-1.exe example1-2.exe \
		example2-1.exe example2-2.exe \
		example3.exe example4.exe \
		example5.exe example6.exe

SOURCES	     =  example1-1.cpp example1-2.cpp \
		example2-1.cpp example2-2.cpp \
		example3.cpp example4.cpp \
		example5.cpp example6.cpp

all: $(SDPA_EXAMPLES)

clean:
	rm -f *.o *.exe

example1-1.exe: example1-1.o
	$(CXX) $(CXXFLAGS) -o $@ example1-1.o -L$(PREFIX)/lib -L$(LOCALBASE)/lib $(LAPACK_LIB) $(SDPA_LIB) -lm

example1-2.exe: example1-2.o
	$(CXX) $(CXXFLAGS) -o $@ example1-2.o -L$(PREFIX)/lib -L$(LOCALBASE)/lib $(LAPACK_LIB) $(SDPA_LIB) -lm

example2-1.exe: example2-1.o
	$(CXX) $(CXXFLAGS) -o $@ example2-1.o -L$(PREFIX)/lib -L$(LOCALBASE)/lib $(LAPACK_LIB) $(SDPA_LIB) -lm

example2-2.exe: example2-2.o
	$(CXX) $(CXXFLAGS) -o $@ example2-2.o -L$(PREFIX)/lib -L$(LOCALBASE)/lib $(LAPACK_LIB) $(SDPA_LIB) -lm

example3.exe: example3.o
	$(CXX) $(CXXFLAGS) -o $@ example3.o -L$(PREFIX)/lib -L$(LOCALBASE)/lib $(LAPACK_LIB) $(SDPA_LIB) -lm

example4.exe: example4.o
	$(CXX) $(CXXFLAGS) -o $@ example4.o -L$(PREFIX)/lib -L$(LOCALBASE)/lib $(LAPACK_LIB) $(SDPA_LIB) -lm

example5.exe: example5.o
	$(CXX) $(CXXFLAGS) -o $@ example5.o -L$(PREFIX)/lib -L$(LOCALBASE)/lib $(LAPACK_LIB) $(SDPA_LIB) -lm

example6.exe: example6.o
	$(CXX) $(CXXFLAGS) -o $@ example6.o -L$(PREFIX)/lib -L$(LOCALBASE)/lib $(LAPACK_LIB) $(SDPA_LIB) -lm

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -I$(PREFIX)/include -I$(LOCALBASE)/include -o $@ $< 