$FreeBSD$

# This is a BitKeeper generated diff -Nru style patch.
#
# ChangeSet
#   2004/02/03 03:22:19+01:00 matthias.andree@gmx.de 
#   e2fsck.c:
#     Add missing ctx->flags &= ~E2F_FLAG_SETJMP_OK; when
#     returning after setjmp returned true (i. e. from longjmp).
# 
# e2fsck/e2fsck.c
#   2004/02/03 03:16:40+01:00 matthias.andree@gmx.de +3 -1
#   Add missing ctx->flags &= ~E2F_FLAG_SETJMP_OK; when
#   returning after setjmp returned true (i. e. from longjmp).
# 
diff -Nru a/e2fsck/e2fsck.c b/e2fsck/e2fsck.c
--- a/e2fsck/e2fsck.c	Tue Feb  3 03:23:50 2004
+++ b/e2fsck/e2fsck.c	Tue Feb  3 03:23:50 2004
@@ -180,8 +180,10 @@
 	pass_t	e2fsck_pass;
 
 #ifdef HAVE_SETJMP_H
-	if (setjmp(ctx->abort_loc))
+	if (setjmp(ctx->abort_loc)) {
+		ctx->flags &= ~E2F_FLAG_SETJMP_OK;
 		return (ctx->flags & E2F_FLAG_RUN_RETURN);
+	}
 	ctx->flags |= E2F_FLAG_SETJMP_OK;
 #endif
 		
