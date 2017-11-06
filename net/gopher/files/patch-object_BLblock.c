--- object/BLblock.c.orig	2003-08-18 16:58:55 UTC
+++ object/BLblock.c
@@ -118,7 +118,7 @@ BLinit(Blockobj *bl)
 	  STAinit(bl->data.text);
 	  break;
      case BDATA_NONE:
-     }
+     break;}
 }
 
 /*
@@ -141,7 +141,8 @@ BLdatadestroy(Blockobj *bl)
 	  GSdestroy(bl->data.gs);
 	  break;
      case BDATA_NONE:
-     }
+     break;
+	}
 }
 
 /*
@@ -174,7 +175,8 @@ BLcpy(Blockobj *dest, Blockobj *orig)
 	  BLsetText(dest, orig->data.text);
 	  break;
      case BDATA_NONE:
-     }
+     break;
+	}
 }
 
 
@@ -209,7 +211,8 @@ BLgetLine(Blockobj *bl, int lineno)
      case BDATA_NONE:
      case BDATA_FILE:
      case BDATA_GREF:
-     }
+     break;
+	}
      return(NULL);
 }
 
@@ -343,7 +346,8 @@ BLtoNet(Blockobj *bl, int fd, boolean sh
 	  fclose(infile);
 	  break;
      case BDATA_NONE:
-     }
+     break;
+	}
 }
 
 
