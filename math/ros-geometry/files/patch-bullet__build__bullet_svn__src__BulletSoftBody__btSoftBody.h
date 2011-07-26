--- bullet/build/bullet_svn/src/BulletSoftBody/btSoftBody.h.orig	2010-05-14 20:51:20.000000000 +0200
+++ bullet/build/bullet_svn/src/BulletSoftBody/btSoftBody.h	2011-07-26 22:33:15.000000000 +0200
@@ -182,12 +182,14 @@
 		btScalar				m_kAST;			// Area/Angular stiffness coefficient [0,1]
 		btScalar				m_kVST;			// Volume stiffness coefficient [0,1]
 		int						m_flags;		// Flags
+		Material() : Element() {}
 	};
 
 	/* Feature		*/ 
 	struct	Feature : Element
 	{
 		Material*				m_material;		// Material
+		Feature() : Element() {}
 	};
 	/* Node			*/ 
 	struct	Node : Feature
@@ -201,6 +203,7 @@
 		btScalar				m_area;			// Area
 		btDbvtNode*				m_leaf;			// Leaf data
 		int						m_battach:1;	// Attached
+		Node() : Feature() {}
 	};
 	/* Link			*/ 
 	struct	Link : Feature
@@ -212,6 +215,7 @@
 		btScalar				m_c1;			// rl^2
 		btScalar				m_c2;			// |gradient|^2/c0
 		btVector3				m_c3;			// gradient
+		Link() : Feature() {}
 	};
 	/* Face			*/ 
 	struct	Face : Feature
@@ -220,6 +224,7 @@
 		btVector3				m_normal;		// Normal
 		btScalar				m_ra;			// Rest area
 		btDbvtNode*				m_leaf;			// Leaf data
+		Face() : Feature() {}
 	};
 	/* Tetra		*/ 
 	struct	Tetra : Feature
@@ -230,6 +235,7 @@
 		btVector3				m_c0[4];		// gradients
 		btScalar				m_c1;			// (4*kVST)/(im0+im1+im2+im3)
 		btScalar				m_c2;			// m_c1/sum(|g0..3|^2)
+		Tetra() : Feature() {}
 	};
 	/* RContact		*/ 
 	struct	RContact
@@ -271,6 +277,7 @@
 		int						m_rank;			// Rank
 		Node*					m_nodes[4];		// Nodes
 		btScalar				m_coords[4];	// Coordinates
+		Note() : Element() {}
 	};	
 	/* Pose			*/ 
 	struct	Pose
