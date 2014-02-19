--- ./bitcoin-qt.pro.orig	2014-01-10 01:38:53.000000000 +0000
+++ ./bitcoin-qt.pro	2014-02-09 05:45:03.127008564 +0000
@@ -431,7 +431,7 @@
 LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 win32:LIBS += -lws2_32 -lshlwapi -lmswsock -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
 win32:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 macx:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 
