--- libs/gcu/spacegroup.cc.orig	2016-11-23 13:05:34 UTC
+++ libs/gcu/spacegroup.cc
@@ -340,7 +340,7 @@ list<Vector> SpaceGroup::Transform (const Vector &v) c
 Transform3d const * SpaceGroup::GetFirstTransform (list <Transform3d*>::const_iterator &i) const
 {
 	i = m_Transforms.begin ();
-	return (i == m_Transforms.end())? reinterpret_cast <Transform3d *> (NULL): *i;
+	return (i == m_Transforms.end())? static_cast <Transform3d *> (NULL): *i;
 }
 
 /*!
@@ -348,7 +348,7 @@ Transform3d const * SpaceGroup::GetFirstTransform (lis
 Transform3d const * SpaceGroup::GetNextTransform (list <Transform3d*>::const_iterator &i) const
 {
 	i++;
-	return (i == m_Transforms.end ())? reinterpret_cast <Transform3d *> (NULL): *i;
+	return (i == m_Transforms.end ())? static_cast <Transform3d *> (NULL): *i;
 }
 
 /*!
