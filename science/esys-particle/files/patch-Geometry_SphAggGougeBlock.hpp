--- Geometry/SphAggGougeBlock.hpp.orig	2018-11-05 04:51:07 UTC
+++ Geometry/SphAggGougeBlock.hpp
@@ -36,7 +36,7 @@ namespace esys {
     void SphAggGougeBlock::visitParticles(TmplVisitor& visitor) const
     {
       GougeBlock3D::visitParticles(visitor);
-      for(vector<SBG_ptr>::iterator it = m_grainParticleGen.begin();
+      for(auto it = m_grainParticleGen.begin();
 	  it != m_grainParticleGen.end();
 	  it++)
 	{
