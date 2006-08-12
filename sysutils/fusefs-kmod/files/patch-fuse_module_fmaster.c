--- fuse_module/fmaster.c	Mon Jun 19 22:10:26 2006 +0200
+++ fuse_module/fmaster.c	Mon Jun 19 22:23:08 2006 +0200
@@ -506,22 +506,22 @@ fuse_response_prettyprint(enum fuse_opco
 	case FUSE_FSYNCDIR:
 		//pp_buf(fresp);
 		break;
-#if FUSE_HAS_GETLK
+#ifdef FUSE_HAS_GETLK
 	case FUSE_GETLK:
 		panic("FUSE_GETLK implementor has forgotten to define a response body format check");
 		break;
 #endif
-#if FUSE_HAS_SETLK
+#ifdef FUSE_HAS_SETLK
 	case FUSE_SETLK:
 		panic("FUSE_SETLK implementor has forgotten to define a response body format check");
 		break;
 #endif
-#if FUSE_HAS_SETLKW
+#ifdef FUSE_HAS_SETLKW
 	case FUSE_SETLKW:
 		panic("FUSE_SETLKW implementor has forgotten to define a response body format check");
 		break;
 #endif
-#if FUSE_HAS_ACCESS
+#ifdef FUSE_HAS_ACCESS
 	case FUSE_ACCESS:
 		break;
 #endif