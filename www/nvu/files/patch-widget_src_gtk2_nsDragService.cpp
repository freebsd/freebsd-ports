--- widget/src/gtk2/nsDragService.cpp.nograb	2007-01-16 21:26:49.000000000 -0500
+++ widget/src/gtk2/nsDragService.cpp	2007-01-16 21:27:04.000000000 -0500
@@ -799,7 +799,6 @@
 void
 nsDragService::GetTargetDragData(GdkAtom aFlavor)
 {
-    gtk_grab_add(mHiddenWidget);
     PR_LOG(sDragLm, PR_LOG_DEBUG, ("getting data flavor %d\n", aFlavor));
     PR_LOG(sDragLm, PR_LOG_DEBUG, ("mLastWidget is %p and mLastContext is %p\n",
                                    mTargetWidget, mTargetDragContext));
@@ -817,7 +816,6 @@
         gtk_main_iteration();
     }
     PR_LOG(sDragLm, PR_LOG_DEBUG, ("finished inner iteration\n"));
-    gtk_grab_remove(mHiddenWidget);
 }
 
 void
