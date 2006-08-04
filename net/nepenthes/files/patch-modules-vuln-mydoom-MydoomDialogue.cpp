--- modules/vuln-mydoom/MydoomDialogue.cpp.old	Sun May  7 16:03:52 2006
+++ modules/vuln-mydoom/MydoomDialogue.cpp	Sun May  7 16:05:33 2006
@@ -120,7 +120,7 @@
 				m_Download = new Download(msg->getRemoteHost(),"mydoom://foo/bar",msg->getRemoteHost(),"some triggerline");
 				m_Download->getDownloadBuffer()->addData((char *)m_Buffer->getData(),m_Buffer->getSize());
 				m_Buffer->clear();
-				return CL_ASSIGN;
+				return CL_ASSIGN_AND_DONE;
 			}
 		}
 		if (m_Buffer->getSize() > 128 )
@@ -130,6 +130,7 @@
 	case MYDOOM_FILETRANSFERR:
 		{
 			m_Download->getDownloadBuffer()->addData((char *)msg->getMsg(),msg->getSize());
+			return CL_ASSIGN_AND_DONE;
 		}
 		break;
 
@@ -196,7 +197,6 @@
 	if (m_Download != NULL)
 	{
     	g_Nepenthes->getSubmitMgr()->addSubmission(m_Download);
-		return CL_ASSIGN_AND_DONE;
 	}
 	return CL_DROP;
 }
