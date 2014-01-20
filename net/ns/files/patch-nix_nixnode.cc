--- nix/nixnode.cc.orig	2014-01-17 10:33:55.000000000 +0100
+++ nix/nixnode.cc	2014-01-17 10:35:51.000000000 +0100
@@ -156,8 +156,6 @@
   if (last.first == NODE_NONE)
     {
       prev = m_Adj.begin();
-      if (prev == (EdgeVec_it) NULL) // ! How can this happen?
-        return(NodeWeight_t(NODE_NONE, 0));
       pE = *prev;
       if(0)printf("NextAdj returning first edge %ld\n",
              pE->m_n);
