--- Code/Common/itkParametricPath.txx.orig	2004-12-04 16:22:44.000000000 +0300
+++ Code/Common/itkParametricPath.txx	2013-12-18 22:34:31.538947309 +0400
@@ -43,7 +43,7 @@
   ContinuousIndexType continuousIndex;
   IndexType           index;
   
-  continuousIndex = Evaluate( input );
+  continuousIndex = this->Evaluate( input );
   
   // Round each coordinate to the nearest integer value
   for( unsigned int i=0; i<VDimension; i++ )
@@ -136,7 +136,7 @@
     inputStepSize = this->EndOfInput() - input;
     }
   
-  return ( Evaluate(input + inputStepSize) - Evaluate(input) ) / inputStepSize;
+  return ( this->Evaluate(input + inputStepSize) - this->Evaluate(input) ) / inputStepSize;
 }
 
 template<unsigned int VDimension>
