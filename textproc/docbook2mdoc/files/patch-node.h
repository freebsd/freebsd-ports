--- node.h.orig	2019-05-02 13:37:55 UTC
+++ node.h
@@ -41,6 +41,7 @@ enum	nodeid {
  */
 enum	nodeid {
 	NODE_ABSTRACT,
+	NODE_ADDRESS,
 	NODE_APPENDIX,
 	NODE_ARG,
 	NODE_AUTHOR,
