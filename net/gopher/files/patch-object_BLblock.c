
$FreeBSD$

--- object/BLblock.c.orig	Sun Aug 22 15:52:31 2004
+++ object/BLblock.c	Sun Aug 22 15:53:33 2004
@@ -118,7 +118,7 @@
 	  STAinit(bl->data.text);
 	  break;
      case BDATA_NONE:
-     }
+     break;}
 }
 
 /*
@@ -141,7 +141,8 @@
 	  GSdestroy(bl->data.gs);
 	  break;
      case BDATA_NONE:
-     }
+     break;
+	}
 }
 
 /*
@@ -174,7 +175,8 @@
 	  BLsetText(dest, orig->data.text);
 	  break;
      case BDATA_NONE:
-     }
+     break;
+	}
 }
 
 
@@ -209,7 +211,8 @@
      case BDATA_NONE:
      case BDATA_FILE:
      case BDATA_GREF:
-     }
+     break;
+	}
      return(NULL);
 }
 
@@ -343,7 +346,8 @@
 	  fclose(infile);
 	  break;
      case BDATA_NONE:
-     }
+     break;
+	}
 }
 
 
