
$FreeBSD$

--- async/dnsparse.C.orig
+++ async/dnsparse.C
@@ -323,7 +323,7 @@
   n_chars += strlen (name) + 1;
 
   ref <mxlist> mxl = refcounted<mxlist, vsize>::alloc
-    (offsetof (mxlist, m_mxes[nmx]) + n_chars);
+    (offsetof (mxlist, m_mxes) + n_chars);
   mxrec *mxrecs = mxl->m_mxes;
   char *np = (char *) &mxrecs[nmx];
 
