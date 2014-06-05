--- ./src-QT4/kdiff3.cpp.orig	2012-07-14 05:27:14.000000000 -0500
+++ ./src-QT4/kdiff3.cpp	2014-06-05 09:45:18.677611475 -0500
@@ -210,6 +210,8 @@
       m_outputFilename = args->getOption("output");
       if ( m_outputFilename.isEmpty() )
          m_outputFilename = args->getOption("out");
+      if ( ! m_outputFilename.isEmpty() )
+         m_outputFilename = FileAccess( m_outputFilename, true ).absoluteFilePath();
    }
 
    m_bAutoFlag = args!=0  && args->isSet("auto");
