--- dix/events.c
+++ dix/events.c
@@ -3420,7 +3420,6 @@ CheckPassiveGrabsOnWindow(
     {
 	DeviceIntPtr	gdev;
 	XkbSrvInfoPtr	xkbi = NULL;
-	Mask		mask = 0;
 
 	gdev= grab->modifierDevice;
         if (grab->grabtype == GRABTYPE_CORE)
@@ -3535,9 +3534,6 @@ CheckPassiveGrabsOnWindow(
                 }
                 xE = &core;
                 count = 1;
-                mask = grab->eventMask;
-                if (grab->ownerEvents)
-                    mask |= pWin->eventMask;
             } else if (match & XI2_MATCH)
             {
                 rc = EventToXI2((InternalEvent*)event, &xE);
@@ -3549,34 +3545,6 @@ CheckPassiveGrabsOnWindow(
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
@@ -3587,23 +3555,6 @@ CheckPassiveGrabsOnWindow(
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
@@ -3612,7 +3563,8 @@ CheckPassiveGrabsOnWindow(
             {
                 FixUpEventFromWindow(device, xE, grab->window, None, TRUE);
 
-                TryClientEvents(rClient(grab), device, xE, count, mask,
+                TryClientEvents(rClient(grab), device, xE, count,
+                                       GetEventFilter(device, xE),
                                        GetEventFilter(device, xE), grab);
             }
 
