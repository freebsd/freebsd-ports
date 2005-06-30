--- Toolkit.cxx.orig	Thu Jun 30 12:09:18 2005
+++ Toolkit.cxx	Thu Jun 30 12:10:07 2005
@@ -783,18 +783,19 @@
 		m_Config = new PConfig(m_ConfigFilePath, m_ConfigDefaultSection);
 	}
 
-	if (!m_extConfigFilePath)
+	if (!m_extConfigFilePath) {
 		PFile::Remove(m_extConfigFilePath);
 	
-	// generate a unique name
-	do {
-		m_extConfigFilePath = tmpdir + PDIR_SEPARATOR + "gnugk.ini-" + PString(PString::Unsigned, rand()%10000);
-		PTRACE(5, "GK\tTrying file name "<< m_extConfigFilePath << " for external config");
-	} while (PFile::Exists(m_extConfigFilePath));
+		// generate a unique name
+		do {
+			m_extConfigFilePath = tmpdir + PDIR_SEPARATOR + "gnugk.ini-" + PString(PString::Unsigned, rand()%10000);
+			PTRACE(5, "GK\tTrying file name "<< m_extConfigFilePath << " for external config");
+		} while (PFile::Exists(m_extConfigFilePath));
 
-	m_Config = new GatekeeperConfig(
-		m_extConfigFilePath, m_ConfigDefaultSection, m_Config
-		);
+		m_Config = new GatekeeperConfig(
+			m_extConfigFilePath, m_ConfigDefaultSection, m_Config
+			);
+	}
 }
 
 void Toolkit::ReloadSQLConfig()
