--- src/NodeEditor/SrcNode.H.orig	2008-04-19 18:19:27.000000000 +0400
+++ src/NodeEditor/SrcNode.H	2013-08-30 16:56:41.373227557 +0400
@@ -4,7 +4,7 @@
 
 #include "INode.H"
 
-class nle::NodeFilter;
+namespace nle { class NodeFilter; }
 class SrcNode : public INode
 {
 	public:
