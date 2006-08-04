--- modules/vuln-bagle/BagleDialogue.cpp.old	Sun May  7 16:07:25 2006
+++ modules/vuln-bagle/BagleDialogue.cpp	Sun May  7 16:08:14 2006
@@ -158,6 +158,7 @@
 				m_State = BAGLE_BINARY;
 				m_Download = new Download(m_Socket->getRemoteHost(),"bagle://",m_Socket->getRemoteHost(),"bagle://foo/bar");
 				m_Download->getDownloadBuffer()->addData(msg->getMsg()+4,msg->getSize()-4);
+				return CL_ASSIGN_AND_DONE;
 			}
 		}
 		break;
@@ -165,6 +166,7 @@
 	case BAGLE_BINARY:
 		// FIXME m_MaxFileSize
 		m_Download->getDownloadBuffer()->addData(msg->getMsg(),msg->getSize());
+		return CL_ASSIGN_AND_DONE;
 		break;
 
 	}
@@ -232,8 +234,6 @@
 		if ( m_Download->getDownloadBuffer()->getSize() == m_FileSize )
 		{
 			g_Nepenthes->getSubmitMgr()->addSubmission(m_Download);
-			// destructor will delete it
-			return CL_ASSIGN_AND_DONE;
 		}
 	}
 	return CL_DROP;
