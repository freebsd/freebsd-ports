--- client/Wayland/wlfreerdp.c.orig	2023-12-14 18:03:49 UTC
+++ client/Wayland/wlfreerdp.c
@@ -587,7 +587,7 @@ static void wlf_client_free(freerdp* instance, rdpCont
 	DeleteCriticalSection(&wlf->critical);
 }
 
-static void* uwac_event_clone(const void* val)
+static void* uwac_event_clone(void* val)
 {
 	UwacEvent* copy;
 	UwacEvent* ev = (UwacEvent*)val;
