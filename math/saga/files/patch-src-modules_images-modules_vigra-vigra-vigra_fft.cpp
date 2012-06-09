--- src/modules_images/modules_vigra/vigra/vigra_fft.cpp.orig	2011-11-24 15:24:43.000000000 +0100
+++ src/modules_images/modules_vigra/vigra/vigra_fft.cpp	2012-01-18 23:21:38.000000000 +0100
@@ -89,7 +89,7 @@
 	{
 		for(int x=0; x<Real.Get_NX(); x++)
 		{
-			Image(x, y)	= FFTWComplex(Real.asDouble(x, y), Imag.asDouble(x, y));
+			Image(x, y)	= FFTWComplex<double>(Real.asDouble(x, y), Imag.asDouble(x, y));
 		}
 	}
 
@@ -296,7 +296,7 @@
 		fourierTransformInverse(srcImageRange(tmp)  , destImage(Output));
 	}
  
-	transformImage(srcImageRange(Output), destImage(Output), std::bind1st(std::multiplies<FFTWComplex>(), 1.0 / Get_NX() / Get_NY()));
+	transformImage(srcImageRange(Output), destImage(Output), std::bind1st(std::multiplies<FFTWComplex<double> >(), 1.0 / Get_NX() / Get_NY()));
 
 	//-----------------------------------------------------
 	pReal	= Parameters("REAL_OUT")->asGrid();
@@ -519,7 +519,7 @@
 
 	vigra::applyFourierFilter(srcImageRange(Input), srcImage(Filter_), destImage(Output));
  
-	transformImage(srcImageRange(Output), destImage(Output), std::bind1st(std::multiplies<FFTWComplex>(), 1.0 / Get_NX() / Get_NY()));
+	transformImage(srcImageRange(Output), destImage(Output), std::bind1st(std::multiplies<FFTWComplex<double> >(), 1.0 / Get_NX() / Get_NY()));
 
 	//-----------------------------------------------------
 	Copy_ComplexGrid_VIGRA_to_SAGA(*pReal, *pImag, Output, false);
