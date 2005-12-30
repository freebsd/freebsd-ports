--- pci_pm.c.orig	Tue Aug 17 19:38:04 2004
+++ pci_pm.c	Fri Dec 30 23:05:40 2005
@@ -64,7 +64,7 @@
 			comt = "Intel8XX(ICH/ICH2/ICH3/ICH4/ICH5/ICH6)";
 			break;
 		case AMD756SMB:
-			comt = "AMD756/766/768";
+			comt = "AMD756/766/768/8111";
 			break;
 		case NFORCESMB:
 			comt = "NVidia nForce";
@@ -166,6 +166,7 @@
 		case ID_AMD756:
 		case ID_AMD766:
 		case ID_AMD768:
+		case ID_AMD8111_1:
 			ret = AMD756SMB;
 			inq_smbba = getSMBBA3;
 			break;
@@ -182,7 +183,7 @@
 				inq_smbba = getSMBBA4;
 			}
 			break;
-		case ID_AMD8111:
+		case ID_AMD8111_2:
 			ret = AMD8111SMB;
 			inq_smbba = getSMBBA6;
 			break;
