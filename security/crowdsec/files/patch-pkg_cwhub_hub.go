--- pkg/cwhub/hub.go.orig	2025-02-10 13:37:25 UTC
+++ pkg/cwhub/hub.go
@@ -165,7 +165,9 @@ func (h *Hub) Update(ctx context.Context, indexProvide
 	}
 
 	if !downloaded {
-		fmt.Println("Nothing to do, the hub index is up to date.")
+		// use logger and the message will be silenced in the cron job
+		// (no mail if nothing happened)
+		h.logger.Info("Nothing to do, the hub index is up to date.")
 	}
 
 	return nil
