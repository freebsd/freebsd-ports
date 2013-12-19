--- Code/Common/itkKLMSegmentationBorder.h.orig	2006-02-07 01:01:56.000000000 +0300
+++ Code/Common/itkKLMSegmentationBorder.h	2013-12-17 17:28:09.961367612 +0400
@@ -80,11 +80,11 @@
 
   bool operator> (const KLMDynamicBorderArray<TBorder>* rhs) const
     {
-    if( m_Pointer->GetLambda() == rhs.m_Pointer->GetLambda() )
+    if( m_Pointer->GetLambda() == rhs->m_Pointer->GetLambda() )
       {
       if( m_Pointer->GetLambda() < 0 )
         {
-        return ( m_Pointer > rhs.m_Pointer );
+        return ( m_Pointer > rhs->m_Pointer );
         }
       else
         {
@@ -99,13 +99,13 @@
           m_Pointer->GetRegion2()->GetRegionBorderSize() );
 
         unsigned int v2 = vnl_math_max(
-          rhs.m_Pointer->GetRegion1()->GetRegionBorderSize(),
-          rhs.m_Pointer->GetRegion2()->GetRegionBorderSize() );
+          rhs->m_Pointer->GetRegion1()->GetRegionBorderSize(),
+          rhs->m_Pointer->GetRegion2()->GetRegionBorderSize() );
 
         return ( v1 > v2 );
         }
       }
-    return(m_Pointer->GetLambda() > rhs.m_Pointer->GetLambda() );
+    return(m_Pointer->GetLambda() > rhs->m_Pointer->GetLambda() );
     }
 
   TBorder *m_Pointer;
