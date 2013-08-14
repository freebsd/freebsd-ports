--- lib/ivykis/lib/include/iv_tls.h.old
+++ lib/ivykis/lib/include/iv_tls.h
@@ -33,7 +33,7 @@ struct iv_tls_user {
 	void		(*deinit_thread)(void *st);
 
 	struct iv_list_head	list;
-	off_t			state_offset;
+	int			state_offset;
 };
 
 void iv_tls_user_register(struct iv_tls_user *);
