--- e-util/e-component-listener.c.orig	Mon Aug  2 11:57:30 2004
+++ e-util/e-component-listener.c	Mon Aug  2 11:58:50 2004
@@ -52,7 +52,7 @@
 			cl->priv->component = CORBA_OBJECT_NIL;
 			g_object_unref (cl);
 			break;
-		default :
+		default :;
 		}
 	}
 }
