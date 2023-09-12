--- client/Wayland/wlfreerdp.c.orig
+++ client/Wayland/wlfreerdp.c
@@ -587,7 +587,7 @@ static void wlf_client_free(freerdp* instance, rdpContext* context)
 	DeleteCriticalSection(&wlf->critical);
 }
 
-static void* uwac_event_clone(const void* val)
+static void* uwac_event_clone(void* val)
 {
 	UwacEvent* copy;
 	const UwacEvent* ev = (const UwacEvent*)val;
