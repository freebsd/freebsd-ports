--- libs/gcu/spacegroup.cc.orig	2018-05-20 17:09:17.854019000 +0200
+++ libs/gcu/spacegroup.cc	2018-05-20 17:22:26.142391000 +0200
@@ -340,7 +340,7 @@
 Transform3d const * SpaceGroup::GetFirstTransform (list <Transform3d*>::const_iterator &i) const
 {
 	i = m_Transforms.begin ();
-	return (i == m_Transforms.end())? reinterpret_cast <Transform3d *> (NULL): *i;
+	return (i == m_Transforms.end())? static_cast <Transform3d *> (NULL): *i;
 }
 
 /*!
@@ -348,7 +348,7 @@
 Transform3d const * SpaceGroup::GetNextTransform (list <Transform3d*>::const_iterator &i) const
 {
 	i++;
-	return (i == m_Transforms.end ())? reinterpret_cast <Transform3d *> (NULL): *i;
+	return (i == m_Transforms.end ())? static_cast <Transform3d *> (NULL): *i;
 }
 
 /*!
