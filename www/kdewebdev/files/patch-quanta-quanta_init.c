--- quanta/quanta_init.orig	Wed Oct 16 21:04:59 2002
+++ quanta/quanta_init.cpp	Wed Oct 16 21:01:26 2002
@@ -1272,8 +1272,8 @@
 //       backAction = KStdAction::back   ( this, SLOT( slotBack() ),    actionCollection(), "w_back" );
 //    forwardAction = KStdAction::forward( this, SLOT( slotForward() ), actionCollection(), "w_forward" );

-    backAction = new KAction ( i18n("Back"), "back", ALT+Key_Left, this, SLOT( slotBack() ),    actionCollection(), "w_back" );
-    forwardAction = new KAction ( i18n("Forward"), "forward", ALT+Key_Right, this, SLOT( slotForward() ),    actionCollection(), "w_forward" );
+//    backAction = new KAction ( i18n("Back"), "back", ALT+Key_Left, this, SLOT( slotBack() ),    actionCollection(), "w_back" );
+//    forwardAction = new KAction ( i18n("Forward"), "forward", ALT+Key_Right, this, SLOT( slotForward() ),    actionCollection(), "w_forward" );

     (void) new KAction( i18n( "&Reload Preview" ), "reload",
                         KStdAccel::key(KStdAccel::Reload),
