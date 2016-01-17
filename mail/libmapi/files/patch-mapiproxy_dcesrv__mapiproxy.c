https://aur.archlinux.org/cgit/aur.git/log/openchange-issue-249.patch?h=openchange

diff -rupN a/mapiproxy/dcesrv_mapiproxy.c b/mapiproxy/dcesrv_mapiproxy.c
--- mapiproxy/dcesrv_mapiproxy.c	2015-06-16 15:41:56.599106174 -0700
+++ mapiproxy/dcesrv_mapiproxy.c	2015-06-16 15:43:29.597211031 -0700
@@ -134,10 +134,10 @@ static NTSTATUS mapiproxy_op_connect(str
 
 		switch (dce_call->pkt.ptype) {
 		case DCERPC_PKT_BIND:
-			b->assoc_group_id = dce_call->pkt.u.bind.assoc_group_id;
+			status = dcerpc_binding_set_assoc_group_id(b, dce_call->pkt.u.bind.assoc_group_id);
 			break;
 		case DCERPC_PKT_ALTER:
-			b->assoc_group_id = dce_call->pkt.u.alter.assoc_group_id;
+			status = dcerpc_binding_set_assoc_group_id(b, dce_call->pkt.u.alter.assoc_group_id);
 			break;
 		default:
 			break;
@@ -154,7 +154,7 @@ static NTSTATUS mapiproxy_op_connect(str
 		if (!NT_STATUS_IS_OK(status)) {
 			return status;
 		}
-		dce_call->context->assoc_group->id = private->c_pipe->assoc_group_id;
+		dce_call->context->assoc_group->id = dcerpc_binding_get_assoc_group_id(private->c_pipe->binding);
 		
 	} else {
 		status = dcerpc_pipe_connect(dce_call->context,
@@ -169,7 +169,7 @@ static NTSTATUS mapiproxy_op_connect(str
 		if (!NT_STATUS_IS_OK(status)) {
 			return status;
 		}
-		dce_call->context->assoc_group->id = private->c_pipe->assoc_group_id;
+		dce_call->context->assoc_group->id = dcerpc_binding_get_assoc_group_id(private->c_pipe->binding);
 	}
 
 	private->connected = true;
