--- testsmb.c.orig	2004-08-12 04:34:48 UTC
+++ testsmb.c
@@ -105,8 +105,9 @@ int main()
 	case ID_AMD756:
 	case ID_AMD766:
 	case ID_AMD768:
+	case ID_AMD8111_1:
 		smbus = &smbus_amd;
-		fprintf(stderr, "AMD756/766/768 found.\n");
+		fprintf(stderr, "AMD756/766/768/8111 found.\n");
 		break;
 	case ID_NFORCE:
 		smbus = &smbus_amd;
@@ -116,9 +117,9 @@ int main()
 		smbus = &smbus_ali;
 		fprintf(stderr, "ALi M1535D+ found.\n");
 		break;
-	case ID_AMD8111:
+	case ID_AMD8111_2:
 		smbus = &smbus_amd8;
-		fprintf(stderr, "AMD8111 found.\n");
+		fprintf(stderr, "AMD8111 SMBus 2.0 found.\n");
 		break;
 	case ID_NFORCE2:
 		smbus = &smbus_amd8;
@@ -126,7 +127,7 @@ int main()
 		break;
 	default:
 		fprintf(stderr, "No known SMBus(I2C) chip found.\n");
-		goto exit;
+		continue;
 	}
 
 	if(OpenIO() == -1) return -1;
@@ -141,7 +142,6 @@ int main()
 	}
 	
 	CloseIO();
-exit:
 	;	/* dummy statment for gcc 3.4 or after */
 
   } /* endo of Big loop for smb_base candidates */
