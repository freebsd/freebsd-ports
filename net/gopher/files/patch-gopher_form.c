--- gopher/form.c.orig	2003-08-18 16:58:14 UTC
+++ gopher/form.c
@@ -288,7 +288,8 @@ FORMgetAskdata(GopherObj *gs, FORM *form
                case ITEM_UNINIT: /* Unhandled cases... */
                case ITEM_LABEL:
                case ITEM_FILENAME:
-	       }
+	       break;
+		}
 	  }
 	  responses[respnum++] = NULL;
      }
