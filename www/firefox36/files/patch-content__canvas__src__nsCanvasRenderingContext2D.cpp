Index: content/canvas/src/nsCanvasRenderingContext2D.cpp
===================================================================
RCS file: /cvsroot/mozilla/content/canvas/src/nsCanvasRenderingContext2D.cpp,v
retrieving revision 1.102
diff -u -8 -p -r1.102 nsCanvasRenderingContext2D.cpp
--- content/canvas/src/nsCanvasRenderingContext2D.cpp	10 Oct 2007 20:31:45 -0000	1.102
+++ content/canvas/src/nsCanvasRenderingContext2D.cpp	11 Oct 2007 23:31:32 -0000
@@ -2140,17 +2140,17 @@ nsCanvasRenderingContext2D::CairoSurface
                                      getter_AddRefs(imgRequest));
         NS_ENSURE_SUCCESS(rv, rv);
         if (!imgRequest)
             // XXX ERRMSG we need to report an error to developers here! (bug 329026)
             return NS_ERROR_NOT_AVAILABLE;
 
         PRUint32 status;
         imgRequest->GetImageStatus(&status);
-        if (status != imgIRequest::STATUS_LOAD_COMPLETE)
+        if ((status & imgIRequest::STATUS_LOAD_COMPLETE) == 0)
             return NS_ERROR_NOT_AVAILABLE;
 
         nsCOMPtr<nsIURI> uri;
         rv = imageLoader->GetCurrentURI(uriOut);
         NS_ENSURE_SUCCESS(rv, rv);
 
         *forceWriteOnlyOut = PR_FALSE;
 
