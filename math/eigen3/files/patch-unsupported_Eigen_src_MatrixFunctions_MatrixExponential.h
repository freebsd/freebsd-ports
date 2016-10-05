Back out 8125108ba3e8 to unbreak consumers on libstdc++ 4.2

  In file included from /usr/local/include/eigen3/unsupported/Eigen/MatrixFunctions:58,
                   from modules/contrib/src/rgbdodometry.cpp:65:
  /usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/MatrixExponential.h: In member function 'void Eigen::MatrixExponential<MatrixType>::computeUV(float)':
  /usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/MatrixExponential.h:296: error: call of overloaded 'pow(int, int&)' is ambiguous
  /usr/include/math.h:210: note: candidates are: double pow(double, double)
  /usr/include/c++/4.2/cmath:357: note:                 float std::pow(float, float)
  /usr/include/c++/4.2/cmath:361: note:                 long double std::pow(long double, long double)
  /usr/include/c++/4.2/cmath:365: note:                 double std::pow(double, int)
  /usr/include/c++/4.2/cmath:369: note:                 float std::pow(float, int)
  /usr/include/c++/4.2/cmath:373: note:                 long double std::pow(long double, int)

--- unsupported/Eigen/src/MatrixFunctions/MatrixExponential.h.orig	2016-07-18 14:28:24 UTC
+++ unsupported/Eigen/src/MatrixFunctions/MatrixExponential.h
@@ -293,7 +293,11 @@
     const float maxnorm = 3.925724783138660f;
     frexp(m_l1norm / maxnorm, &m_squarings);
     if (m_squarings < 0) m_squarings = 0;
+#if !defined(__GLIBCXX__) || __GLIBCXX__ > 20070831
     MatrixType A = m_M / Scalar(pow(2, m_squarings));
+#else
+    MatrixType A = m_M / pow(Scalar(2), m_squarings);
+#endif
     pade7(A);
   }
 }
@@ -315,7 +315,11 @@
     const double maxnorm = 5.371920351148152;
     frexp(m_l1norm / maxnorm, &m_squarings);
     if (m_squarings < 0) m_squarings = 0;
+#if !defined(__GLIBCXX__) || __GLIBCXX__ > 20070831
     MatrixType A = m_M / Scalar(pow(2, m_squarings));
+#else
+    MatrixType A = m_M / pow(Scalar(2), m_squarings);
+#endif
     pade13(A);
   }
 }
@@ -340,7 +340,11 @@
     const long double maxnorm = 4.0246098906697353063L;
     frexp(m_l1norm / maxnorm, &m_squarings);
     if (m_squarings < 0) m_squarings = 0;
+#if !defined(__GLIBCXX__) || __GLIBCXX__ > 20070831
     MatrixType A = m_M / Scalar(pow(2, m_squarings));
+#else
+    MatrixType A = m_M / pow(Scalar(2), m_squarings);
+#endif
     pade13(A);
   }
 #elif LDBL_MANT_DIG <= 106  // double-double
@@ -376,7 +376,11 @@
     const long double maxnorm = 2.884233277829519311757165057717815L;
     frexp(m_l1norm / maxnorm, &m_squarings);
     if (m_squarings < 0) m_squarings = 0;
+#if !defined(__GLIBCXX__) || __GLIBCXX__ > 20070831
     MatrixType A = m_M / Scalar(pow(2, m_squarings));
+#else
+    MatrixType A = m_M / pow(Scalar(2), m_squarings);
+#endif
     pade17(A);
   }
 #else
