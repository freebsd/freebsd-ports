--- protolib/unix/bsdRouteMgr.cpp.orig	2009-05-08 18:44:06.000000000 -0300
+++ protolib/unix/bsdRouteMgr.cpp	2009-05-08 18:44:35.000000000 -0300
@@ -255,7 +255,7 @@
             }  // end if(mask[i] is set)
         }  // end for(i=0..RTAX_MAX)
         if (dst.IsValid() && 
-            (0 == (rtm->rtm_flags & RTF_WASCLONED)))
+            (0 == (rtm->rtm_flags)))
         {
             if (prefixLen < 0) prefixLen = dst.GetLength() << 3;
             if (0 == (rtm->rtm_flags & RTF_GATEWAY)) gw.Invalidate();
