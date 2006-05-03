Index: render/mitri.c
===================================================================
RCS file: /cvs/xorg/xserver/xorg/render/mitri.c,v
retrieving revision 1.5
diff -u -r1.5 mitri.c
--- programs/Xserver/render/mitri.c	3 Jul 2005 07:02:08 -0000	1.5
+++ programs/Xserver/render/mitri.c	18 Apr 2006 22:34:08 -0000
@@ -145,7 +145,7 @@
     if (npoint < 3)
 	return;
     ntri = npoint - 2;
-    tris = ALLOCATE_LOCAL (ntri & sizeof (xTriangle));
+    tris = ALLOCATE_LOCAL (ntri * sizeof (xTriangle));
     if (!tris)
 	return;
     for (tri = tris; npoint >= 3; npoint--, points++, tri++)
@@ -177,7 +177,7 @@
     if (npoint < 3)
 	return;
     ntri = npoint - 2;
-    tris = ALLOCATE_LOCAL (ntri & sizeof (xTriangle));
+    tris = ALLOCATE_LOCAL (ntri * sizeof (xTriangle));
     if (!tris)
 	return;
     first = points++;
