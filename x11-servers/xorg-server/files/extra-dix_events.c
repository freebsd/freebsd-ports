--- dix/events.c.orig	2010-05-04 02:47:57.000000000 +0200
+++ dix/events.c	2012-04-24 12:59:22.000000000 +0200
@@ -3440,7 +3440,6 @@ CheckPassiveGrabsOnWindow(
     {
 	DeviceIntPtr	gdev;
 	XkbSrvInfoPtr	xkbi = NULL;
-	Mask		mask = 0;
 
 	gdev= grab->modifierDevice;
         if (grab->grabtype == GRABTYPE_CORE)
@@ -3555,9 +3554,6 @@ CheckPassiveGrabsOnWindow(
                 }
                 xE = &core;
                 count = 1;
-                mask = grab->eventMask;
-                if (grab->ownerEvents)
-                    mask |= pWin->eventMask;
             } else if (match & XI2_MATCH)
             {
                 rc = EventToXI2((InternalEvent*)event, &xE);
@@ -3569,34 +3565,6 @@ CheckPassiveGrabsOnWindow(
                     continue;
                 }
                 count = 1;
-
-                /* FIXME: EventToXI2 returns NULL for enter events, so
-                 * dereferencing the event is bad. Internal event types are
-                 * aligned with core events, so the else clause is valid.
-                 * long-term we should use internal events for enter/focus
-                 * as well */
-                if (xE)
-                    mask = grab->xi2mask[device->id][((xGenericEvent*)xE)->evtype/8];
-                else if (event->type == XI_Enter || event->type == XI_FocusIn)
-                    mask = grab->xi2mask[device->id][event->type/8];
-
-                if (grab->ownerEvents && wOtherInputMasks(grab->window))
-                {
-                    InputClientsPtr icp =
-                        wOtherInputMasks(grab->window)->inputClients;
-
-                    while(icp)
-                    {
-                        if (rClient(icp) == rClient(grab))
-                        {
-                            int evtype = (xE) ? ((xGenericEvent*)xE)->evtype : event->type;
-                            mask |= icp->xi2mask[device->id][evtype/8];
-                            break;
-                        }
-
-                        icp = icp->next;
-                    }
-                }
             } else
             {
                 rc = EventToXI((InternalEvent*)event, &xE, &count);
@@ -3607,23 +3575,6 @@ CheckPassiveGrabsOnWindow(
                                 "(%d, %d).\n", device->name, event->type, rc);
                     continue;
                 }
-                mask = grab->eventMask;
-                if (grab->ownerEvents && wOtherInputMasks(grab->window))
-                {
-                    InputClientsPtr icp =
-                        wOtherInputMasks(grab->window)->inputClients;
-
-                    while(icp)
-                    {
-                        if (rClient(icp) == rClient(grab))
-                        {
-                            mask |= icp->mask[device->id];
-                            break;
-                        }
-
-                        icp = icp->next;
-                    }
-                }
             }
 
 	    (*grabinfo->ActivateGrab)(device, grab, currentTime, TRUE);
@@ -3632,7 +3583,8 @@ CheckPassiveGrabsOnWindow(
             {
                 FixUpEventFromWindow(device, xE, grab->window, None, TRUE);
 
-                TryClientEvents(rClient(grab), device, xE, count, mask,
+                TryClientEvents(rClient(grab), device, xE, count,
+                                       GetEventFilter(device, xE),
                                        GetEventFilter(device, xE), grab);
             }
 
