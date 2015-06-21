--- pci_pm.c.orig	2004-08-17 16:38:04 UTC
+++ pci_pm.c
@@ -64,7 +64,7 @@ char *chk_smb_chip(int chip)
 			comt = "Intel8XX(ICH/ICH2/ICH3/ICH4/ICH5/ICH6)";
 			break;
 		case AMD756SMB:
-			comt = "AMD756/766/768";
+			comt = "AMD756/766/768/8111";
 			break;
 		case NFORCESMB:
 			comt = "NVidia nForce";
@@ -158,6 +158,7 @@ int pci_pm_smb_prob(int *hwm_base, int *
 		case ID_I801CA:
 		case ID_I801DB:
 		case ID_I801EB:
+		case ID_I801IB:
 		case ID_I6300ESB:
 		case ID_IICH6:
 			ret = ICH801SMB;
@@ -166,6 +167,7 @@ int pci_pm_smb_prob(int *hwm_base, int *
 		case ID_AMD756:
 		case ID_AMD766:
 		case ID_AMD768:
+		case ID_AMD8111_1:
 			ret = AMD756SMB;
 			inq_smbba = getSMBBA3;
 			break;
@@ -182,7 +184,7 @@ int pci_pm_smb_prob(int *hwm_base, int *
 				inq_smbba = getSMBBA4;
 			}
 			break;
-		case ID_AMD8111:
+		case ID_AMD8111_2:
 			ret = AMD8111SMB;
 			inq_smbba = getSMBBA6;
 			break;
