--- kbruch/src/mainqtwidget.cpp.orig	Sat Jun  5 03:34:59 2004
+++ kbruch/src/mainqtwidget.cpp	Sat Jun  5 03:40:39 2004
@@ -92,7 +92,7 @@
 	m_maxMainDenominator = m_config->readNumEntry("max_main_denominator", 10);
 
    /* make sure that we can load config files with corrupted values */
-   if (m_mulDiv == true and pow(2, m_nrRatios) > m_maxMainDenominator)
+   if (m_mulDiv == true && pow(2, m_nrRatios) > m_maxMainDenominator)
    {
       m_nrRatios = 2;
       m_maxMainDenominator = 10;
