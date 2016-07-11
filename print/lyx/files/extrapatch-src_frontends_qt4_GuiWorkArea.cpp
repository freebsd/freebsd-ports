This patch is necessary for FreeBSD 10.0 and 10.1, whose libc++ does not work
with boost and std::bind() and leads to the following failure:

frontends/qt4/liblyxqt4.a(GuiWorkArea.o): In function `_ZN5boost6detail8function26void_function_obj_invoker0INSt3__16__bindIMN3lyx8frontend11GuiWorkAreaEFvvEJPS7_EEEvE6invokeERNS1_15function_bufferE':
GuiWorkArea.cpp:(.text._ZN5boost6detail8function26void_function_obj_invoker0INSt3__16__bindIMN3lyx8frontend11GuiWorkAreaEFvvEJPS7_EEEvE6invokeERNS1_15function_bufferE[_ZN5boost6detail8function26void_function_obj_invoker0INSt3__16__bindIMN3lyx8frontend11GuiWorkAreaEFvvEJPS7_EEEvE6invokeERNS1_15function_bufferE]+0xa): undefined reference to `_ZNSt3__18__invokeIRMN3lyx8frontend11GuiWorkAreaEFvvERPS3_JEvEEDTcldsdeclsr3std3__1E7forwardIT0_Efp0_Efp_spclsr3std3__1E7forwardIT1_Efp1_EEEOT_OS9_DpOSA_'
/usr/bin/ld: lyx: hidden symbol `_ZNSt3__18__invokeIRMN3lyx8frontend11GuiWorkAreaEFvvERPS3_JEvEEDTcldsdeclsr3std3__1E7forwardIT0_Efp0_Efp_spclsr3std3__1E7forwardIT1_Efp1_EEEOT_OS9_DpOSA_' isn't defined
/usr/bin/ld: final link failed: Nonrepresentable section on output

--- src/frontends/qt4/GuiWorkArea.cpp.orig	2016-05-23 23:47:31 UTC
+++ src/frontends/qt4/GuiWorkArea.cpp
@@ -55,6 +55,8 @@
 #include "frontends/FontMetrics.h"
 #include "frontends/WorkAreaManager.h"
 
+#include <boost/bind.hpp>
+
 #include <QContextMenuEvent>
 #if (QT_VERSION < 0x050000)
 #include <QInputContext>
@@ -320,7 +322,7 @@ void GuiWorkArea::init()
 	d->setCursorShape(Qt::IBeamCursor);
 
 	d->synthetic_mouse_event_.timeout.timeout.connect(
-		bind(&GuiWorkArea::generateSyntheticMouseEvent,
+               boost::bind(&GuiWorkArea::generateSyntheticMouseEvent,
 					this));
 
 	// Initialize the vertical Scroll Bar
