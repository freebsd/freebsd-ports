--- nm_gnu.mak.orig	2014-02-14 09:47:53.000000000 +0100
+++ nm_gnu.mak	2014-02-14 09:49:32.000000000 +0100
@@ -9,7 +9,7 @@
 %.o:           	%.cpp
 		$(CXX) $(CXXFLAGS) -c $*.cpp
 
-everything:    	tmt example nm_ex1 nm_ex2 nm_ex3 test_exc nl_ex sl_ex garch 
+everything:    	tmt example nm_ex1 nm_ex2 nm_ex3 test_exc nl_ex sl_ex garch libnewmat.so.1
 
 newmat_lobj = newmat1.o newmat2.o newmat3.o newmat4.o newmat5.o newmat6.o newmat7.o newmat8.o newmatex.o bandmat.o submat.o myexcept.o cholesky.o evalue.o fft.o hholder.o jacobi.o newfft.o sort.o svd.o nm_misc.o newmatrm.o newmat9.o
 
@@ -17,6 +17,9 @@
 		$(AR) -cr $@ $(newmat_lobj)
 		ranlib $@
 
+libnewmat.so.1:	$(newmat_lobj)
+		$(CXX) $(CXXFLAGS) -shared -Wl,-soname=$@ -o $@ $(newmat_lobj)
+
 tmt_obj = tmt.o tmt1.o tmt2.o tmt3.o tmt4.o tmt5.o tmt6.o tmt7.o tmt8.o tmt9.o tmta.o tmtb.o tmtc.o tmtd.o tmte.o tmtf.o tmtg.o tmth.o tmti.o tmtj.o tmtk.o tmtl.o tmtm.o
 
 tmt:           	$(tmt_obj) libnewmat.a
