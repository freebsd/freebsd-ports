commit 10b33821cfd79375cfdbe05123b2f7f6329eac3e
Author: Jerry Snitselaar <jsnitsel@redhat.com>
Date:   Wed Jan 16 14:00:43 2019 -0700

    trousers: clean up use after free in Transport_TerminateHandle
    
    Clean up possible use after free. The value of the handles pointer
    may change, but if it doesn't then free is being called twice on
    the same address.
    
    Signed-off-by: Jerry Snitselaar <jsnitsel@redhat.com>

diff --git src/tspi/tsp_auth.c src/tspi/tsp_auth.c
index d538079..5a97e6e 100755
--- src/tspi/tsp_auth.c
+++ src/tspi/tsp_auth.c
@@ -1221,17 +1221,17 @@ Transport_TerminateHandle(TSS_HCONTEXT tspContext, /* in */
 	}
 
 	*handles = handle;
-    handles_track = handles;
+	handles_track = handles;
 
-    // Since the call tree of this function can possibly alloc memory 
-    // (check RPC_ExecuteTransport_TP function), its better to keep track of
-    // the handle.
+	// Since the call tree of this function can possibly alloc memory
+	// (check RPC_ExecuteTransport_TP function), its better to keep track of
+	// the handle.
 	result = obj_context_transport_execute(tspContext, TPM_ORD_Terminate_Handle, 0, NULL,
 					       NULL, &handlesLen, &handles, NULL, NULL, NULL, NULL);
 
-	free(handles);
-    handles = NULL;
-    free(handles_track);
+	if (handles != handles_track)
+		free(handles);
+	free(handles_track);
 
 	return result;
 }
